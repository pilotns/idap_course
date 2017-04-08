//
//  AMPFirstHomeTask.c
//  AMPStudy
//
//  Created by pilotns on 08.04.17.
//  Copyright © 2017 pilotns. All rights reserved.
//

#include "AMPFirstHomeTask.h"

static const char * const AMPMama = "mama";
static const char * const AMPPapa = "papa";
static const char * const AMPNewLine = "\n";

void AMPPrintString(const char *string) {
    printf("%s", string);
}

void AMPPrintStringWithValue(int value) {
    if (0 == (value % 3)) {
        AMPPrintString(AMPMama);
    }
    
    if (0 == (value % 5)) {
        AMPPrintString(AMPPapa);
    }
    
    AMPPrintString(AMPNewLine);
}

void AMPPrintStringWithIterationCount(int count) {
    for (int iterator = 1; iterator < count; iterator++) {
        printf("iteration - #%d - ", iterator);
        AMPPrintStringWithValue(iterator);
    }
}
