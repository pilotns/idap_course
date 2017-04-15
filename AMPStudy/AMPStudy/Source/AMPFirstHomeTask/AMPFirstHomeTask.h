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

typedef void (*AMPShouldPrintString)(int, int, const char *);

void AMPShouldPrintStringWithValueAndDivisor(int value, int divisor, const char *string);
void AMPPrintStringWithValueAndFunction(int value, AMPShouldPrintString shouldPrint);
void AMPPrintStringWithIterationCount(int count);

#endif /* AMPFirstHomeTask_h */
