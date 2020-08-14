//
//  Car.cpp
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
#include "Car.h"
#include "iostream"
#include <cstring>
#include <stdio.h>

using namespace std;
namespace sdds {

    Car::Car()
    {
        carWashFlag = false;
    }

    Car::Car(const char* license, const char* Make_Model) :Vehicle(license, Make_Model)
    {
        
        if(license != nullptr && strlen(license) > 0 && strlen(license) < 9 && Make_Model != nullptr && strlen(Make_Model) > 2) {
            carWashFlag = false;
        } else {
            Car();
        }
    }

    std::istream& Car::read(std::istream& is)
    {
        char temp2;
        char temp;
        bool tempcond;
        bool temp2cond;
        
        if (isCsv())
        {
            Vehicle::read(is);
            is >> carWashFlag;
            is.ignore(2000, '\n');
        }
        else
        {
            cout << "\n";
            cout << "Car information entry" << endl;
            Vehicle::read(is);
            cout << "Carwash while parked? (Y)es/(N)o: ";
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
                carWashFlag = 1;
            } else {
                carWashFlag = 0;
            }
        }
        return is;
    }

    std::ostream& Car::write(std::ostream& os) const
    {
        if(Vehicle::isEmpty()) {
            os << "Invalid Car Object" << endl;
        } else {
            if (isCsv()) {
            
            os << "C,";
            
            } else {
                os << "Vehicle type: Car" << endl;
            }
        
            Vehicle::write(os);
            if(isCsv()) {
                os << carWashFlag << endl;
            } else {
                if(carWashFlag == 0){
                    os << "Without Carwash" << endl;
                } else {
                    os << "With Carwash" << endl;
                }
            }
        }
        return os;
    }
}
