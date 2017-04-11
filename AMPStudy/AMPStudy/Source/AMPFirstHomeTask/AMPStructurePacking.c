//
//  AMPStructurePacking.c
//  AMPStudy
//
//  Created by pilotns on 09.04.17.
//  Copyright © 2017 pilotns. All rights reserved.
//

#include "AMPStructurePacking.h"

#include <stdlib.h>

#include "AMPMacros.h"

void AMPPrintMembersOffset(void) {
    AMPPrintOffsetof(AMPStructurePacking, string);
    AMPPrintOffsetof(AMPStructurePacking, doubleValue);
    AMPPrintOffsetof(AMPStructurePacking, longLongValue);
    AMPPrintOffsetof(AMPStructurePacking, intValue);
    AMPPrintOffsetof(AMPStructurePacking, floatValue);
    AMPPrintOffsetof(AMPStructurePacking, shortValue1);
    AMPPrintOffsetof(AMPStructurePacking, shortValue2);
    AMPPrintOffsetof(AMPStructurePacking, shortValue3);
    AMPPrintOffsetof(AMPStructurePacking, bitfields);
}

void AMPPrintSize() {
    printf("size = %lu\n", sizeof(AMPStructurePacking));
}
