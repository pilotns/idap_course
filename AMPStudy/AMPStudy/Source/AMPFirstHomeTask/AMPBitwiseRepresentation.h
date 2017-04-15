//
//  AMPBitwiseRepresentation.h
//  AMPStudy
//
//  Created by pilotns on 09.04.17.
//  Copyright © 2017 pilotns. All rights reserved.
//

#ifndef AMPBitwiseRepresentation_h
#define AMPBitwiseRepresentation_h

#include <stdio.h>
#include <stdbool.h>

bool AMPIsBigEndian(void);
void AMPBitwiseRepresentationPrintMemoryWithSize(void *memory, size_t size, bool isBigendian);

#endif /* AMPBitwiseRepresentation_h */
