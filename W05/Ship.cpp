//
//  Ship.cpp
//  W05
//
//  Created by Shabnoor Sayed on 2020-06-28.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Ship.h"
using namespace std;

namespace sdds
{
    Ship::Ship()
    {
        m_type[0]='\0';
        numEngine=0;
        distance = 0.0;
    }
    Ship::Ship(const char type[], Engine arr[], int num)
    {
        if (strlen(type) <= 6 && num >= 1)
        {
            for (int i = 0; i < num; i++)
            {
                object[i] = arr[i];
            }
            strcpy(m_type, type);
            numEngine = num;
        }
        else
        {
            m_type[0] = '\0';
            numEngine = 0;
        }
    }
    bool Ship::empty() const
    {
        return(m_type[0] == '\0' && numEngine == 0);
    }
    explicit bool Ship::operator() const
    {
        return true;
        
    }

    float Ship::calculatePower() const
    {
        float power=0;
        for (int i = 0; i < numEngine; i++)
        {
            power += (float)object[i].get() * 5;
        }
        return power;
    }
    void Ship::display() const
    {
        if (empty())
        {
            cout << "No available data" << endl;
        }
        else
        {

            double pwr;
            pwr = calculatePower();
            cout << m_type<<"-";
            cout.setf(ios::fixed);
            cout.width(6);
            cout.precision(2);
            cout << pwr<<endl;
            for (int i = 0; i < numEngine; i++)
            {
                object[i].display();
            }
        }
    }
    Ship& Ship::operator+=(Engine e)
    {
        if (!empty())
        {
            if (numEngine < 10)
            {
                
                    object[numEngine++] = e;
              
            }
        }
        else
        {
            cout << "The object doesn't have a type! Engine cannot be added!"<<endl;
        }
        return *this;
    }
    bool operator==(const Ship& p, const Ship& s)
    {
        return p.calculatePower() == s.calculatePower();
    }
    bool operator<(const Ship& p, double pwr )
    {
        return p.calculatePower() < pwr;
    }

}
