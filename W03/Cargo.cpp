//
//  Cargo.cpp
//  W03
//
//  Created by Shabnoor Sayed on 2020-06-13.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#include <stdio.h>
#include "Train.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Cargo.h"

using namespace std;

namespace sdds {

    void Cargo::initialize(const char* desc, double weight)
    {
        if(strlen(desc)<= (MAX_DESC+1)) {
            
            setDesc(desc);
        } else {
            
            setDesc("\0");
        }
        setWeight(weight);
    }

    const char* Cargo::getDesc() const
    {
        return desc;
    }

    double Cargo::getWeight() const
    {
        return validWeight;
    }

    void Cargo::setDesc(const char* description)
    {
        strcpy(desc,description);
    }

    void Cargo::setWeight(double weight)
    {
        if(weight >= MIN_WEIGHT && weight <= MAX_WEIGHT) {
            validWeight = weight;
        } else {
            validWeight = MIN_WEIGHT;
        }
    }
}
