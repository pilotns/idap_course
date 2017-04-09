//
//  AMPStructurePacking.c
//  AMPStudy
//
//  Created by pilotns on 09.04.17.
//  Copyright © 2017 pilotns. All rights reserved.
//

#include "AMPStructurePacking.h"

#include <stdbool.h>
#include <stdlib.h>

#include "AMPMacros.h"


struct AMPStructurePacking {
    short       shortValue1;
    long long   longLongValue;
    bool        boolValue1;
    int         intValue;
    bool        boolValue2;
    float       floatValue;
    bool        boolValue3;
    bool        boolValue4;
    short       shortValue2;
    bool        boolValue5;
    double      doubleValue;
    bool        boolValue6;
    short       shortValue3;
    char        *string;
};


void AMPPrintMembersOffset(void) {
    AMPPrintOffsetof(AMPStructurePacking, boolValue1);
    AMPPrintOffsetof(AMPStructurePacking, boolValue2);
    AMPPrintOffsetof(AMPStructurePacking, boolValue3);
    AMPPrintOffsetof(AMPStructurePacking, boolValue4);
    AMPPrintOffsetof(AMPStructurePacking, boolValue5);
    AMPPrintOffsetof(AMPStructurePacking, boolValue6);
    AMPPrintOffsetof(AMPStructurePacking, floatValue);
    AMPPrintOffsetof(AMPStructurePacking, intValue);
    AMPPrintOffsetof(AMPStructurePacking, longLongValue);
    AMPPrintOffsetof(AMPStructurePacking, shortValue1);
    AMPPrintOffsetof(AMPStructurePacking, shortValue2);
    AMPPrintOffsetof(AMPStructurePacking, shortValue3);
    AMPPrintOffsetof(AMPStructurePacking, doubleValue);
    AMPPrintOffsetof(AMPStructurePacking, string);
}

void AMPPrintSize() {
    printf("size = %lu\n", sizeof(AMPStructurePacking));
}
