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

void AMPPrintStringWithValue(int value) {
    if (0 == (value % 15)) {
        printf("%s%s\n", AMPMama, AMPPapa);
    } else if (0 == (value % 5)) {
        printf("%s\n", AMPPapa);
    } else if (0 == (value % 3)) {
        printf("%s\n", AMPMama);
    } else {
        printf("\n");
    }
}

void AMPPrintStringWithIterationCount(int count) {
    for (int iterator = 1; iterator < count; iterator++) {
        printf("iteration - #%d - ", iterator);
        AMPPrintStringWithValue(iterator);
    }
}
