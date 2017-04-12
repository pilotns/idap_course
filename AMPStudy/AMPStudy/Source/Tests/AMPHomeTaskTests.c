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
#include "AMPArrayTest.h"

static const int AMPDefaultIterationCount = 1000;

AMPOutputWithTypeAndFormatter(int, %d);
AMPOutputWithTypeAndFormatter(char, %c);
AMPOutputWithTypeAndFormatter(float, %f);
AMPOutputWithTypeAndFormatter(double, %.15lf);
AMPOutputWithTypeAndFormatter(long, %ld);

void AMPMacrosTest(void) {
    AMPCallOutputMacroWithType(char, 'c');
    AMPCallOutputMacroWithType(int, 10);
    AMPCallOutputMacroWithType(long, UINT32_MAX);
    AMPCallOutputMacroWithType(float, 1.5);
    AMPCallOutputMacroWithType(double, M_PI);
}

void AMPStructurePackingTest(void) {
    AMPPrintMembersOffset();
    AMPPrintSize();
}

void AMPBitwiseRepresentationTest(void) {
    AMPStructurePacking structure = {0};
    
    structure.bitfields = 255;
    
    structure.boolValue1 = 0;
    structure.boolValue2 = 0;
    structure.boolValue3 = 0;
    
    AMPBitviseRepresentationPrintMemoryWithSize(&structure, sizeof(structure), AMPIsBigendian());
}

void AMPHomeTaskTest(void) {
    AMPCallTest(AMPPrintStringWithIterationCount, AMPDefaultIterationCount);
    AMPCallTest(AMPMacrosTest, AMPEmptyParameter);
    AMPCallTest(AMPStructurePackingTest, AMPEmptyParameter);
    AMPCallTest(AMPBitwiseRepresentationTest, AMPEmptyParameter);
    AMPCallTest(AMPArrayTest, AMPEmptyParameter);
}
