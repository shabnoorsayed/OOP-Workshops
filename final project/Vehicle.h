//
//  Vehicle.hpp
//  M1
//
//  Created by Shabnoor Sayed on 2020-07-25.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//
/*------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef Vehicle_h
#define Vehicle_h

#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"
#include "Menu.h"
#include "ReadWritable.h"
#include "iostream"
#include <cstring>
#include <stdio.h>

namespace sdds {

    class Vehicle : public ReadWritable
    {

        char licensePlate[9];
        char* Make_Model;
        int spotNum;
    public:
        Vehicle();
        Vehicle(const char* license, const char* model_make);
        ~Vehicle();
        Vehicle(const Vehicle&) = delete;
        Vehicle& operator=(const Vehicle&) = delete;
        int getParkingSpot() const;
        void setParkingSpot(int parkSpot);
        bool operator==(const char* license) const;
        bool operator==(const Vehicle& plate) const;
        std::istream& read(std::istream& is);
        std::ostream& write(std::ostream& os) const;
    protected:
        void setEmpty();
        bool isEmpty() const;
        char* getLicensePlate() const;
        char* getMakeModel() const;
        void setMakeModel(const char* makeModel);
        void setLicensePlate(const char* license);
    };
}

#endif /* Vehicle_h */
