//
//  Cargo.hpp
//  W03
//
//  Created by Shabnoor Sayed on 2020-06-10.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//
// Name: Shabnoor Sayed
// Email: ssayed10@myseneca.ca
// Student Id: 133649194
// Date: 13-June-2020
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef Cargo_h
#define Cargo_h

#include <stdio.h>

namespace sdds
{
    const int MAX_DESC = 20;
    const double MAX_WEIGHT = 777.555;
    const double MIN_WEIGHT = 44.2222;

    class Cargo
    {
        char desc[MAX_DESC+1];
        double validWeight;
        
    public:
        
        void initialize(const char* desc, double weight);
        const char* getDesc() const;
        double getWeight() const;
        void setDesc(const char* description);
        void setWeight(double weight);
    };
}

#endif /* Cargo_h */
