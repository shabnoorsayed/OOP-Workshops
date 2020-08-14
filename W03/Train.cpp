//
//  Train.cpp
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

#define _CRT_SECURE_NO_WARNINGS

#include "Train.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Cargo.h"

using namespace std;

namespace sdds {

    void Train::initialize(const char *name, int id)
    {
        if((name == nullptr) || (strcmp(name,"\0") == 0)) {
            
            
            strcpy(validName, "\0");
        } else {
            
            strcpy(validName, name);
        }
        
        if(id < 1) {
            
            validId = 0;
        } else {
            
            validId = id;
            
        }
        validCargo = nullptr;
    }

    bool Train::isValid() const
    {
        if((strcmp(validName, "\0") == 0) || (validId == 0)) {
            return false;
        }
        return true;
    }
    
    void Train::loadCargo(Cargo car)
    {
        
            if(validCargo == nullptr){
                validCargo = new Cargo();
            }
            validCargo->setDesc(car.getDesc());
            validCargo->setWeight(car.getWeight());
    }

    void Train::unloadCargo()
    {
        delete validCargo;
        validCargo = nullptr;
    }

    bool Train::swapCargo(Train& other)
    {
        if(validCargo == nullptr && other.validCargo == nullptr) {
            
            return false;
        } else {
            
            Cargo* temp = validCargo;
            validCargo = other.validCargo;
            other.validCargo = temp;
            
            return true;
        }
    }

    bool Train::increaseCargo(double weight)
    {
        bool increase = true;
        if(validCargo == nullptr || !isValid() || validCargo->getWeight() >= MAX_WEIGHT) {
            
            increase = false;
        } else if((validCargo->getWeight() + weight) > MAX_WEIGHT) {
            
            validCargo->setWeight(MAX_WEIGHT);
        } else {
            
            validCargo->setWeight(validCargo->getWeight()+weight);
            increase = true;
        }
        return increase;
    }

    bool Train::decreaseCargo(double weight)
    {
        bool decrease = true;
        
        if(validCargo == nullptr || !isValid() || validCargo->getWeight() <= MIN_WEIGHT) {
            
            decrease = false;
        } else if(validCargo->getWeight() - weight < MIN_WEIGHT) {
            
            validCargo->setWeight(MIN_WEIGHT);
        } else {
            
            validCargo->setWeight(validCargo->getWeight()-weight);
            decrease = true;
        }
        return decrease;
    }

    void Train::display()const
    {
        cout << "***Train Summary***" << endl;
        if(isValid() == false) {
            
            cout << "This is an invalid train." << endl;
            
        } else if(validCargo == nullptr) {
            
            cout << "    Name: " << validName << endl;
            cout << "      ID: " << validId << endl;
            cout << "No cargo on this train." << endl;
        }else {
                        
                cout << fixed <<setprecision(2);
                cout << "    Name: " << validName << endl;
                cout << "      ID: " << validId << endl;
                cout << "   Cargo: " << validCargo->getDesc() << endl;
                cout << "  Weight: " << validCargo->getWeight() << endl;
                cout.unsetf (ios::floatfield );
                cout.precision(6);
        }
    }
}
