//
//  AMPStructurePacking.h
//  AMPStudy
//
//  Created by pilotns on 09.04.17.
//  Copyright © 2017 pilotns. All rights reserved.
//

#ifndef AMPStructurePacking_h
#define AMPStructurePacking_h

#include <stdio.h>
#include <stdbool.h>

typedef struct AMPStructurePacking AMPStructurePacking;

struct AMPStructurePacking {
    char        *string;
    double      doubleValue;
    long long   longLongValue;
    int         intValue;
    float       floatValue;
    short       shortValue1;
    short       shortValue2;
    short       shortValue3;
    struct {
        bool        boolValue1: 1;
        bool        boolValue2: 1;
        bool        boolValue3: 1;
        bool        boolValue4: 1;
        bool        boolValue5: 1;
        bool        boolValue6: 1;
    };
//    union {
//        bool        boolValue1;
//        bool        boolValue2;
//        bool        boolValue3;
//        bool        boolValue4;
//        bool        boolValue5;
//        bool        boolValue6;
//    };
};

void AMPPrintMembersOffset(void);
void AMPPrintSize(void);

#endif /* AMPStructurePacking_h */
