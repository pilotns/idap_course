//
//  AMPFirstHomeTask.c
//  AMPStudy
//
//  Created by pilotns on 08.04.17.
//  Copyright © 2017 pilotns. All rights reserved.
//

#include "AMPFirstHomeTask.h"

#include <stdbool.h>

#include "AMPMacros.h"

static const char * const AMPMama = "mama";
static const char * const AMPPapa = "papa";
static const char * const AMPNewLine = "\n";

bool AMPShouldPrintStringWithValueAndDivisor(int value, int divisor) {
    return !(value % divisor);
}

void AMPPrintStringWithValueAndFunction(int value, AMPShouldPrintString shouldPrint) {
    if (shouldPrint(value, 3)) {
        AMPPrintString(AMPMama);
    }
    
    if (shouldPrint(value, 5)) {
        AMPPrintString(AMPPapa);
    }
    
    AMPPrintString(AMPNewLine);
}

void AMPPrintStringWithIterationCount(int count) {
    for (int iterator = 1; iterator < count; iterator++) {
        if (!AMPShouldPrintStringWithValueAndDivisor(iterator, 3)
            && !AMPShouldPrintStringWithValueAndDivisor(iterator, 5))
        {
            continue;
        }
        
        printf("iteration - #%d - ", iterator);
        AMPPrintStringWithValueAndFunction(iterator, AMPShouldPrintStringWithValueAndDivisor);
    }
}
