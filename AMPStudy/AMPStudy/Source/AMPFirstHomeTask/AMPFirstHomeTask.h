//
//  AMPFirstHomeTask.h
//  AMPStudy
//
//  Created by pilotns on 08.04.17.
//  Copyright © 2017 pilotns. All rights reserved.
//

#ifndef AMPFirstHomeTask_h
#define AMPFirstHomeTask_h

#include <stdio.h>
#include <stdbool.h>

typedef bool (*AMPShouldPrintString)(int, int);

bool AMPShouldPrintStringWithValueAndDivisor(int value, int divisor);
void AMPPrintString(const char *string);
void AMPPrintStringWithValueAndFunction(int value, bool (*shouldPrint)(int, int));
void AMPPrintStringWithIterationCount(int count);

#endif /* AMPFirstHomeTask_h */
