//
//  Ship.hpp
//  W05
//
//  Created by Shabnoor Sayed on 2020-06-28.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#pragma once
#ifndef SDDS_SHIP_H__
#define SDDS_SHIP_H__
#include "Engine.h"

namespace sdds
{
    const double MIN_STD_POWER = 90.111;
    const double MAX_STD_POWER = 99.999;

    class Ship
    {
        Engine object[10];
        char m_type[TYPE_MAX_SIZE];
        int numEngine;
        double distance;

    public:

        Ship();
        Ship(const char[], Engine [], int);
        bool empty() const;
        explicit operator bool() const;
        float calculatePower() const;
        void display() const;
        Ship& operator+=(Engine e);
        

    };
    bool operator==(const Ship&, const Ship&);
    bool operator<(const Ship&, double);


}

#endif /* Ship_h */
