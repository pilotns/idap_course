//
//  AMPBitwiseRepresentation.c
//  AMPStudy
//
//  Created by pilotns on 09.04.17.
//  Copyright © 2017 pilotns. All rights reserved.
//

#include "AMPBitwiseRepresentation.h"

static const int AMPBitsPerByte = 8;

void AMPBitwiseRepresentationPrintByte(char *byte, bool isBigendian);

void AMPBitwiseRepresentationPrintMemoryWithSize(void *memory, size_t size, bool isBigendian) {
    int iterator = 0;
    while (iterator < size) {
        if (isBigendian) {
            AMPBitwiseRepresentationPrintByte(memory + (size-iterator-1), isBigendian);
        } else {
            AMPBitwiseRepresentationPrintByte(memory++, isBigendian);
        }
        iterator++;
    }
    printf("\n");
}

void AMPBitwiseRepresentationPrintByte(char *byte, bool isBigendian) {
    
    for (int iterator = 0; iterator < AMPBitsPerByte; iterator++) {
        char b = *byte;
        if (isBigendian) {
            b >>= (AMPBitsPerByte - iterator - 1);
        } else {
            b >>= iterator;
        }
        
        printf("%d", b & 1 ? 1 : 0);
    }
    printf(" ");
}
