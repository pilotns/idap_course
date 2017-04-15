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

void AMPShouldPrintStringWithValueAndDivisor(int value, int divisor, const char *string) {
    if (!(value % divisor)) {
        AMPPrintString(string);
    }
}

void AMPPrintStringWithValueAndFunction(int value, AMPShouldPrintString shouldPrint) {
    shouldPrint(value, 3, AMPMama);
    shouldPrint(value, 5, AMPPapa);
    AMPPrintString(AMPNewLine);
}

void AMPPrintStringWithIterationCount(int count) {
    for (int iterator = 1; iterator < count; iterator++) {
        printf("iteration - #%d - ", iterator);
        AMPPrintStringWithValueAndFunction(iterator, AMPShouldPrintStringWithValueAndDivisor);
    }
}
