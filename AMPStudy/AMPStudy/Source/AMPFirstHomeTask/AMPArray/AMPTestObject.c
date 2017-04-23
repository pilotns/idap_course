//
//  AMPTestObject.c
//  AMPStudy
//
//  Created by pilotns on 11.04.17.
//  Copyright © 2017 pilotns. All rights reserved.
//

#include "AMPTestObject.h"

#include <stdlib.h>

struct AMPTestObject {
    uint64_t referenceCount;
    
};

void *AMPTestObjectCreate(void) {
    AMPTestObject *object = calloc(1, sizeof(*object));
    if (NULL != object) {
        object->referenceCount = 1;
    }
    
    return object;
}

void *AMPTestObjectRetain(void *object) {
    if (NULL != object) {
        AMPTestObject *testObject = (AMPTestObject *)object;
        testObject->referenceCount++;
    }
    
    return object;
}

void AMPTestObjectRelease(void *object) {
    if (NULL != object) {
        AMPTestObject *testObject = (AMPTestObject *)object;
        uint64_t referenceCount = --testObject->referenceCount;
        if (!referenceCount) {
            free(object);
        }
    }
}
