//
//  validate.hpp
//  W09P1
//
//  Created by Shabnoor Sayed on 2020-07-29.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#ifndef validate_h
#define validate_h

#include <stdio.h>

template <typename V>

bool validate(const V &min, const V testValue[], int size, bool results[])
{
    bool arr = true;
    
    for(int i = 0; i < size; i++) {
        if(testValue[i] <= min) {
            arr = false;
        }
        results[i] = (testValue[i] >= min);
    }
    
    return arr;
}

#endif /* validate_h */
