//
//  Motorcycle.hpp
//  M1
//
//  Created by Shabnoor Sayed on 2020-07-30.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//
/*------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#ifndef Motorcycle_h
#define Motorcycle_h
#include "Parking.h"
#include "Menu.h"
#include "ReadWritable.h"
#include "Vehicle.h"
#include "Car.h"
#include "iostream"
#include <cstring>
#include <stdio.h>

namespace sdds {
    class Motorcycle : public Vehicle {
        bool sideCarFlag;
    public:
        Motorcycle();
        Motorcycle(const char* license, const char* Make_Model);
        std::istream& read(std::istream& is);
        std::ostream& write(std::ostream& os) const;
    };
}

#endif /* Motorcycle_h */
