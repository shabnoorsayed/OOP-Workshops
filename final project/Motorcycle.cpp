//
//  Motorcycle.cpp
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
#include "Parking.h"
#include "Menu.h"
#include "ReadWritable.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "iostream"
#include <cstring>
#include <stdio.h>

using namespace std;
namespace sdds {

    Motorcycle::Motorcycle()
    {
        sideCarFlag = false;
    }

    Motorcycle::Motorcycle(const char* license, const char* Make_Model) :Vehicle(license, Make_Model)
    {
        if(license != nullptr && strlen(license) > 0 && strlen(license) < 9 && Make_Model != nullptr && strlen(Make_Model) > 2) {
            sideCarFlag = false;
        } else {
            Motorcycle();
        }
    }

    std::istream& Motorcycle::read(std::istream& is)
    {
        char temp2;
        char temp;
        bool tempcond;
        bool temp2cond;
        
        if (isCsv())
        {
            Vehicle::read(is);
            is >> sideCarFlag;
            is.ignore(2000, '\n');
        }
        else
        {
            cout << "\n";
            cout << "Motorcycle information entry" << endl;
            Vehicle::read(is);
            cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
            do {
                
                temp = cin.get();
                temp2 = cin.get();
                cin.clear();
                tempcond = (temp != 'Y') || (temp != 'y') || (temp != 'n') || (temp != 'N');
                temp2cond = (temp2 != '\n');
                
                if((tempcond && temp2cond)) {
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                    cin.ignore(200, '\n');
                }
                
            } while ((tempcond && temp2cond));
            
            if(temp == 'Y' || temp == 'y') {
                sideCarFlag = 1;
            } else {
                sideCarFlag = 0;
            }
        }
        return is;
    }

    std::ostream& Motorcycle::write(std::ostream& os) const
    {
        if(Vehicle::isEmpty()) {
            os << "Invalid Motorcycle Object" << endl;
        } else {
            if (isCsv()) {
            
            os << "M,";
            
            } else {
                os << "Vehicle type: Motorcycle" << endl;
            }
        
            Vehicle::write(os);
            if(isCsv()) {
                os << sideCarFlag << endl;
            } else {
                if(sideCarFlag == 1){
                    os << "With Sidecar" << endl;
                } 
            }
        }
        return os;
    }

}
