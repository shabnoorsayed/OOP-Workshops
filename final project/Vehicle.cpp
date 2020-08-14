//
//  Vehicle.cpp
//  M1
//
//  Created by Shabnoor Sayed on 2020-07-25.
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
#include "iostream"
#include <cstring>
#include <stdio.h>

using namespace std;
namespace sdds
{
    Vehicle::Vehicle()
    {
        this->licensePlate[0] = '\0';
        this->Make_Model = nullptr;
        this->spotNum = 0;
    }
    
    Vehicle::Vehicle(const char license[], const char* model_make)
    {
        this->licensePlate[0] = '\0';
        this->Make_Model = nullptr;
        this->spotNum = 0;
        
        if (license != nullptr && strlen(license) > 0 && strlen(license) < 9 && model_make != nullptr && strlen(model_make) > 2) {
            this->spotNum = 0;
            strcpy(this->licensePlate, license);

            this->Make_Model = new char[strlen(model_make) + 1];
            strcpy(this->Make_Model, model_make);
        }
    }

    int Vehicle::getParkingSpot() const
    {
        return this->spotNum;
    }

    void Vehicle::setParkingSpot(const int parkSpot)
    {
        this->spotNum = -1;
        if (parkSpot >= 0) {
            this->spotNum = parkSpot;
        }
    }

    char* Vehicle::getLicensePlate() const
    {
        char* license = new char[strlen(this->licensePlate) + 1];
        strcpy(license, this->licensePlate);
        return license;
    }

    char* Vehicle::getMakeModel() const
    {
        return this->Make_Model;
    }

    void Vehicle::setMakeModel(const char* makeModel)
    {
        if (this->Make_Model != nullptr)
            delete[] this->Make_Model;

        this->Make_Model = nullptr;
        if (makeModel != nullptr) {
            this->Make_Model = new char[strlen(makeModel) + 1];
            strcpy(this->Make_Model, makeModel);
        }
    }

    void Vehicle::setEmpty()
    {
        this->licensePlate[0] = '\0';
        if (this->Make_Model != nullptr) {
            delete[] this->Make_Model;
        }
        this->Make_Model = nullptr;
        this->spotNum = 0;
    }

    bool Vehicle::isEmpty() const
    {
        bool result = true;
        if(this->licensePlate[0] == '\0' || this->Make_Model == nullptr || this->spotNum < 0) {
            result = true;
        } else {
            result = false;
        }
        return result;
    }

    bool Vehicle::operator== (const char* license) const
    {
        bool flag = false;
        if (license != nullptr && !isEmpty()) {
            char* temp1 = new char[strlen(this->licensePlate) + 1];
            temp1[0] = '\0';
            for (size_t i = 0; i <= strlen(this->licensePlate); i++) {
                temp1[i] = toupper(this->licensePlate[i]);
            }

            char* temp2 = new char[strlen(license) + 1];
            temp2[0] = '\0';
            for (size_t i = 0; i <= strlen(license); i++) {
                temp2[i] = toupper(license[i]);
            }

            if (strcmp(temp1, temp2) == 0) flag = true;
            delete[] temp1;
            delete[] temp2;
        }
        return flag;
    }

    bool Vehicle::operator== (const Vehicle& plate) const
    {
        
        return (*this == plate.licensePlate);
    }

    istream& Vehicle::read(std::istream& is) {
        setEmpty();
        char license[10] = {'\0'};
        int parkSpot = 0;
        string temp;
        bool flag = true;
        int length = 0;
        if (this->isCsv()) {
            if(getline(is,temp, ',')) parkSpot = stoi(temp);
            this->setParkingSpot(parkSpot);

            is.ignore();
            is.get(licensePlate, 8 + 1, ',');
            is.ignore(2000, ',');
            length = strlen(license);
            for (int i = 0; i < length; i++) {
                license[i] = toupper(license[i]);
            }

            if (getline(is,temp, ',')) {
                this->setMakeModel(temp.c_str());
            }
        } else {
            
            cout << "Enter Licence Plate Number: ";
            while (flag)
            {
                
                is.getline(license, 10);
                if (strlen(license) > 8 || strlen(license) == 0 || isspace(license[0]) )
                {
                    cout << "Invalid Licence Plate, try again: ";
                }
                else
                {
                    length = strlen(license);
                    for (int i = 0; i < length; i++) {
                        license[i] = toupper(license[i]);
                    }
                    strcpy(licensePlate, license);
                    flag = false;
                }
            }
            
            cout << "Enter Make and Model: ";
            if (getline(is, temp)){
                while (temp.length() < 2 || temp.length() > 60) {
                    cout << "Invalid Make and model, try again: ";
                    getline(is, temp);
                }

                this->setMakeModel(temp.c_str());
            }
            this->setParkingSpot(0);
        }
        return is;
    }

    ostream& Vehicle::write(ostream& os) const
    {
        if (isEmpty()) {
            os << "Invalid Vehicle Object" << endl;
        } else if(this->isCsv()) {
            os << spotNum << "," << licensePlate << "," << Make_Model << ",";
        } else {
            os << "Parking Spot Number: ";
            if (spotNum == 0) os << "N/A";
            else os << spotNum;
            os << endl;
            os << "Licence Plate: " << licensePlate << endl;
            os << "Make and Model: " << Make_Model << endl;
        }
        return os;
    }

    Vehicle::~Vehicle()
    {
        delete[] this->Make_Model;
    }
}
