//
//  AMPBitwiseRepresentation.c
//  AMPStudy
//
//  Created by pilotns on 09.04.17.
//  Copyright © 2017 pilotns. All rights reserved.
//

#include "AMPBitwiseRepresentation.h"

static const uint16_t AMPValue = 1;
static const int AMPBitsPerByte = 8;

void AMPBitwiseRepresentationPrintByte(char *byte, bool isBigendian);

bool AMPIsBigEndian(void) {
    return *(char *)&AMPValue == 1;
}

void AMPBitwiseRepresentationPrintMemoryWithSize(void *memory, size_t size, bool isBigendian) {
    int iterator = 0;
    while (iterator < size) {
        size_t position = isBigendian ? (size - iterator - 1) : iterator;
        AMPBitwiseRepresentationPrintByte(memory + position, isBigendian);
        iterator++;
    }
    
    printf("\n");
}

void AMPBitwiseRepresentationPrintByte(char *byte, bool isBigendian) {
    for (int iterator = 0; iterator < AMPBitsPerByte; iterator++) {
        char b = *byte;
        int shift = isBigendian ? (AMPBitsPerByte - iterator - 1) : iterator;
        printf("%d", (b >> shift) & 1 ? 1 : 0);
    }
    
    printf(" ");
}
