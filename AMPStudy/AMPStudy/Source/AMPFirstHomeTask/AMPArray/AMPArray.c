//
//  AMPArray.c
//  AMPStudy
//
//  Created by pilotns on 10.04.17.
//  Copyright © 2017 pilotns. All rights reserved.
//

#include "AMPArray.h"

#include <stdlib.h>
#include <string.h>

#include "AMPTestObject.h"
#include "AMPMacros.h"

static const uint64_t AMPArrayDefaultCapacity = 10;

#pragma mark - Private Declaration

struct AMPArray {
    uint64_t referenceCount;
    
    void **storage;
    uint64_t count;
    uint64_t capacity;
};

void AMPArrayDealloc(AMPArray *array);
void AMPArraySetCapacity(AMPArray *array, uint64_t capacity);
void AMPArrayIncrementCount(AMPArray *array);
void AMPArrayDecrementCount(AMPArray *array);

uint64_t AMPArrayExpectedCapacity(AMPArray *array);
uint64_t AMPArrayGetCapacity(AMPArray *array);

#pragma mark - Public Implementation

AMPArray *AMPArrayCreateWithCapacity(uint64_t capacity) {

    AMPArray *array = calloc(1, sizeof(*array));
    
    if (NULL == array) {
        return NULL;
    }
    
    array->referenceCount = 1;

    AMPArraySetCapacity(array, capacity);
    
    return array;
}

void AMPArrayAddObject(AMPArray *array, void *object) {
    if (NULL != object) {
        uint64_t currentCount = AMPArrayGetCount(array);
        
        uint64_t newCapacity = AMPArrayExpectedCapacity(array);
        
        if (UINT64_MAX != newCapacity) {
            AMPArraySetCapacity(array, newCapacity);
        }
        
        array->storage[currentCount] = object;
        
        AMPTestObjectRetain(object);
        AMPArrayIncrementCount(array);
    }
}

void *AMPArrayObjectAtIndex(AMPArray *array, uint64_t index) {
    uint64_t currentCount = AMPArrayGetCount(array);
    void *result = NULL;
    
    if (index < currentCount) {
        result = array->storage[index];
    }
    
    return result;
}

void AMPArrayRemoveObject(AMPArray *array, void *object) {
    uint64_t index = UINT64_MAX;
    
    while (UINT64_MAX != (index = AMPArrayIndexOfObject(array, object))) {
        AMPArrayRemoveObjectAtIndex(array, index);
    }

}

void AMPArrayRemoveAllObjects(AMPArray *array) {
    do {
        AMPArrayRemoveObjectAtIndex(array, 0);
        
    } while(0 != AMPArrayGetCount(array));
}

void AMPArrayRemoveObjectAtIndex(AMPArray *array, uint64_t index) {
    uint64_t currentCount = AMPArrayGetCount(array);
    
    if (index < currentCount) {
        void **position = array->storage + index;
        void *object = *position;
        
        currentCount = currentCount - 1;
        size_t length = (currentCount - index)*sizeof(void *);
        memmove(position, position + 1, length);
        position[currentCount] = NULL;
        
        AMPArrayDecrementCount(array);
        AMPTestObjectRelease(object);
    }
}

uint64_t AMPArrayIndexOfObject(AMPArray *array, void *object) {
    if (NULL == object) {
        return UINT64_MAX;
    }
    
    uint64_t currentCount = AMPArrayGetCount(array);
    
    if (0 != currentCount && UINT64_MAX != currentCount) {
        for (int iterator = 0; iterator < currentCount; iterator++) {
            void *currentObject = AMPArrayObjectAtIndex(array, iterator);
            
            if (currentObject == object) {
                return iterator;
            }
        }
    }
    
    return UINT64_MAX;
}

bool AMPArrayContainsObject(AMPArray *array, void *object) {
    return NULL != array && UINT64_MAX != AMPArrayIndexOfObject(array, object);
}

uint64_t AMPArrayGetCount(AMPArray *array) {
    return NULL != array ? array->count : UINT64_MAX;
}

AMPArray *AMPArrayRetain(AMPArray *array) {
    if (NULL != array) {
        array->referenceCount++;
    }
    
    return array;
}

void AMPArrayRelease(AMPArray *array) {
    if (NULL != array) {
        uint64_t referenceCount = --array->referenceCount;
        
        if (0 == referenceCount) {
            AMPArraySetCapacity(array, 0);
        }
    }
}

#pragma mark - Private Implementation

void AMPArrayDealloc(AMPArray *array) {
    free(array);
}

void AMPArraySetCapacity(AMPArray *array, uint64_t capacity) {
    if (NULL == array) {
        return;
    }
    
    if (capacity == array->capacity) {
        return;
    }
    
    void **storage = array->storage;
    
    array->capacity = capacity;
    
    if (0 == capacity && NULL != storage) {
        AMPArrayRemoveAllObjects(array);
        
        free(storage);
        AMPArrayDealloc(array);
        
    } else {
        size_t size = capacity * sizeof(void *);
        storage = realloc(storage, size);
        array->storage = storage;
    }
}

void AMPArrayIncrementCount(AMPArray *array) {
    if (NULL != array) {
        array->count++;
    }
}

void AMPArrayDecrementCount(AMPArray *array) {
    if (NULL != array) {
        array->count--;
    }
}

uint64_t AMPArrayGetCapacity(AMPArray *array) {
    return NULL != array ? array->capacity : UINT64_MAX;
}

uint64_t AMPArrayExpectedCapacity(AMPArray *array) {
    uint64_t currentCapacity = AMPArrayGetCapacity(array);
    uint64_t currentCount = AMPArrayGetCount(array);
    
    if (UINT64_MAX == currentCount || UINT64_MAX == currentCapacity) {
        return UINT64_MAX;
    }
    
    if (currentCount == currentCapacity) {
        return currentCapacity + AMPArrayDefaultCapacity;
    }
    
    if (currentCount < currentCapacity - AMPArrayDefaultCapacity) {
        return currentCapacity - AMPArrayDefaultCapacity;
    }
    
    return UINT64_MAX;
}
