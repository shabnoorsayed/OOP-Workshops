//
//  Train.hpp
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

#ifndef Train_h
#define Train_h

#include <stdio.h>
#include "Cargo.h"

namespace sdds {

    const int MAX_NAME = 30;

    class Train
    {
        char validName[MAX_NAME+1];
        int validId;
        Cargo* validCargo = nullptr;
        
    public:
        
        void initialize(const char* name, int id);
        bool isValid() const;
        void loadCargo(Cargo car);
        void unloadCargo();
        bool swapCargo(Train& other);
        bool increaseCargo(double weight);
        bool decreaseCargo(double weight);
        void display() const;
    };
}

#endif /* Train_h */
