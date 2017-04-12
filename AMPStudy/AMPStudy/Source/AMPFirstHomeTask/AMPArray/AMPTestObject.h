//
//  AMPTestObject.h
//  AMPStudy
//
//  Created by pilotns on 11.04.17.
//  Copyright © 2017 pilotns. All rights reserved.
//

#ifndef AMPTestObject_h
#define AMPTestObject_h

#include <stdio.h>

#endif /* AMPTestObject_h */

typedef struct AMPTestObject AMPTestObject;

void *AMPTestObjectCreate(void);

void *AMPTestObjectRetain(void *object);
void AMPTestObjectRelease(void *object);
