//
//  Saiyan.hpp
//  WS04
//
//  Created by Shabnoor Sayed on 2020-06-15.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//
// Name: Shabnoor Sayed
// Email: ssayed10@myseneca.ca
// Student Id: 133649194
// Date: 16-June-2020
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef Saiyan_h
#define Saiyan_h

#include <stdio.h>

namespace sdds
{

    class Saiyan
    {
      
        char* m_name = nullptr;
        int m_dob;
        int m_power;
        bool m_super;
        int m_level;
        
    public:
        
        Saiyan();
        Saiyan(const char* name, int dob, int power);
        void set(const char* name, int dob, int power, int level = 0, bool super = false);
        bool isValid() const;
        void display() const;
        bool fight(Saiyan& other);
        void powerUp();
        ~Saiyan();
    };
}

#endif /* Saiyan_h */
