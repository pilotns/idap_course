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
#include "AMPStructurePacking.h"
#include "AMPBitwiseRepresentation.h"

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

void AMPStructurePackingTest(void) {
    AMPPrintMembersOffset();
    AMPPrintSize();
}

void AMPBitwiseRepresentationTest(void) {
    AMPStructurePacking structure = {0};
    
    structure.boolValue1 = 1;
    structure.boolValue2 = 1;
    structure.boolValue3 = 1;
    structure.boolValue4 = 1;
    structure.boolValue5 = 1;
    structure.boolValue6 = 1;
    
    AMPBitviseRepresentationPrintMemoryWithSize(&structure, sizeof(structure), AMPIsBigendian());
}

void AMPHomeTaskTest(void) {
    AMPPrintStringWithIterationCount(AMPDefaultIterationCount);
    AMPMacrosTest();
    AMPStructurePackingTest();
    printf("---------------------------------------------------\n");
    AMPBitwiseRepresentationTest();
}
