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
    char        *string;
    double      doubleValue;
    long long   longLongValue;
    int         intValue;
    float       floatValue;
    short       shortValue1;
    short       shortValue2;
    short       shortValue3;
    union {
        bool        boolValue1;
        bool        boolValue2;
        bool        boolValue3;
        bool        boolValue4;
        bool        boolValue5;
        bool        boolValue6;
    };
};


void AMPPrintMembersOffset(void) {
    AMPPrintOffsetof(AMPStructurePacking, string);
    AMPPrintOffsetof(AMPStructurePacking, doubleValue);
    AMPPrintOffsetof(AMPStructurePacking, longLongValue);
    AMPPrintOffsetof(AMPStructurePacking, intValue);
    AMPPrintOffsetof(AMPStructurePacking, floatValue);
    AMPPrintOffsetof(AMPStructurePacking, shortValue1);
    AMPPrintOffsetof(AMPStructurePacking, shortValue2);
    AMPPrintOffsetof(AMPStructurePacking, shortValue3);
    AMPPrintOffsetof(AMPStructurePacking, boolValue1);
    AMPPrintOffsetof(AMPStructurePacking, boolValue2);
    AMPPrintOffsetof(AMPStructurePacking, boolValue3);
    AMPPrintOffsetof(AMPStructurePacking, boolValue4);
    AMPPrintOffsetof(AMPStructurePacking, boolValue5);
    AMPPrintOffsetof(AMPStructurePacking, boolValue6);
}

void AMPPrintSize() {
    printf("size = %lu\n", sizeof(AMPStructurePacking));
}
