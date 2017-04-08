//
//  AMPHomeTaskTests.c
//  AMPStudy
//
//  Created by pilotns on 09.04.17.
//  Copyright © 2017 pilotns. All rights reserved.
//

#include "AMPHomeTaskTests.h"

#include <math.h>

#include "AMPFirstHomeTask.h"
#include "AMPMacros.h"

static const int AMPDefaultIterationCount = 1000;

AMPOutputWithTypeAndFormatter(int, %d)
AMPOutputWithTypeAndFormatter(char, %c)
AMPOutputWithTypeAndFormatter(float, %f)
AMPOutputWithTypeAndFormatter(double, %.15lf)
AMPOutputWithTypeAndFormatter(long, %ld)

void AMPMacrosTest(void) {
    AMPOutput_char('c');
    AMPOutput_int(10);
    AMPOutput_long(UINT32_MAX);
    AMPOutput_float(1.5);
    AMPOutput_double(M_PI);
}

void AMPHomeTaskTest(void) {
    AMPPrintStringWithIterationCount(AMPDefaultIterationCount);
    AMPMacrosTest();
}
