//
//  AMPArray.h
//  AMPStudy
//
//  Created by pilotns on 10.04.17.
//  Copyright © 2017 pilotns. All rights reserved.
//

#ifndef AMPArray_h
#define AMPArray_h

#include <stdio.h>
#include <stdbool.h>

typedef struct AMPArray AMPArray;

AMPArray *AMPArrayCreateWithCapacity(uint64_t capacity);

void AMPArrayAddObject(AMPArray *array, void *object);
void *AMPArrayObjectAtIndex(AMPArray *array, uint64_t index);

void AMPArrayRemoveObject(AMPArray *array, void *object);
void AMPArrayRemoveAllObjects(AMPArray *array);
void AMPArrayRemoveObjectAtIndex(AMPArray *array, uint64_t index);

uint64_t AMPArrayIndexOfObject(AMPArray *array, void *object);
bool AMPArrayContainsObject(AMPArray *array, void *object);
uint64_t AMPArrayGetCount(AMPArray *array);

AMPArray *AMPArrayRetain(AMPArray *array);
void AMPArrayRelease(AMPArray *array);

#endif /* AMPArray_h */
