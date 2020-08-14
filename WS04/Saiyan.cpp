//
//  Saiyan.cpp
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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Saiyan.h"

using namespace std;

namespace sdds
{

    Saiyan::Saiyan()
    {
        m_name = nullptr;
        m_dob = 0;
        m_power = 0;
        m_super = false;
        m_level = 0;
    }

    Saiyan::Saiyan(const char* name, int dob, int power)
    {
        set(name, dob, power);
    }

    void Saiyan::set(const char* name, int dob, int power, int level, bool super)
    {
        
        bool result = true;
        
        if(m_name != nullptr) {
             
            delete [] m_name;
        }
        if(name != nullptr && name[0] != '\0' && dob <= 2020 && dob >= 0 && power > 0) {
                    
            m_name = nullptr;
            m_name = new char[32];
            strcpy(m_name, name);
            m_dob = dob;
            m_power = power;
            m_super = super;
            m_level = level;
            result = false;
            
        } else if(result) {
            
            Saiyan();
        }
        
    }

    bool Saiyan::isValid() const
    {
        bool result = false;
        
        if(m_name != nullptr && m_name[0] != '\0' && m_dob <= 2020 && m_dob >= 0 && m_power >= 0) {
            
            result = true;
        }
        return result;
    }

    void Saiyan::display() const
    {
        
        if(isValid()){
            
            cout << m_name << endl;
            cout << "     DOB: " << m_dob << endl;
            cout << "   Power: " << m_power << endl;
            if(m_super == 0) {
                cout << "   Super: " << "no" << endl;
            } else {
                cout << "   Super: " << "yes" << endl;
                cout << "   Level: " << m_level << endl;
            }

        } else {
            
            cout << "Invalid Saiyan!" << endl;
        }
    }

    bool Saiyan::fight(Saiyan &other)
    {

        bool win = false;
        powerUp();
        other.powerUp();
        
        if((isValid() && other.isValid()) && m_power > other.m_power) {

            win = true;
        }else {
            
            win = false;
        }
        return win;
    }

    void Saiyan::powerUp()
    {
       if(m_super == 1){
           int powerUp = (m_power * 0.1);
           m_power += powerUp * m_level;
        }
    }

    Saiyan::~Saiyan()
    {
        delete [] m_name;
        m_name = nullptr;
    }

}
