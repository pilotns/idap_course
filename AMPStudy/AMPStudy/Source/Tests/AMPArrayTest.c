//
//  AMPArrayTest.c
//  AMPStudy
//
//  Created by pilotns on 11.04.17.
//  Copyright © 2017 pilotns. All rights reserved.
//

#include "AMPArrayTest.h"

#include <assert.h>

#include "AMPArray.h"
#include "AMPTestObject.h"

void AMPArrayTest(void) {

    AMPArray *array = AMPArrayCreateWithCapacity(10);
    AMPTestObject *object = AMPTestObjectCreate();
    
    for (int iterator = 0; iterator < 20; iterator++) {
        AMPArrayAddObject(array, object);
    }
    
    for (int iterator = 0; iterator < 20; iterator++) {
        AMPTestObject *testObject = AMPArrayObjectAtIndex(array, iterator);
        
        assert(object == testObject);
    }
    
    AMPArrayRemoveObject(array, object);
    
    assert(0 == AMPArrayGetCount(array));

    AMPTestObjectRelease(object);
    AMPArrayRelease(array);
}
