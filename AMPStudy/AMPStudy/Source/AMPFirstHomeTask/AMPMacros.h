//
//  AMPMacros.h
//  AMPStudy
//
//  Created by pilotns on 09.04.17.
//  Copyright © 2017 pilotns. All rights reserved.
//

#ifndef AMPMacros_h
#define AMPMacros_h

#include <stdio.h>

#define AMPOutputWithTypeAndFormatter(type, formatter) \
    void AMPOutput_##type(type value) { \
        printf(#formatter "\n", value); \
    }


#define AMPCallOutputMacroWithType(type, value) \
    AMPOutput_##type(value);

#endif /* AMPMacros_h */
