//
//  Gift.cpp
//  Gift
//
//  Created by Shabnoor Sayed on 2020-06-03.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//
// Name: Shabnoor Sayed
// Email: ssayed10@myseneca.ca
// Student Id: 133649194
// Date: 7-June-2020
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <iostream>
#include "Gift.h"

using namespace std;

namespace sdds
{
    void gifting(char* desc)
    {
        cout << "Enter gift description: ";
        cin.width(MAX_DESC + 1);
        cin >> desc;
    }

    void gifting(double& price)
    {
        cout << "Enter gift price: ";
        cin >> price;
        while (price < 0 || price > MAX_PRICE){
            cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
            cout << "Enter gift price: ";
            cin >> price;
        }
    }

    void gifting(int& units)
    {
        cout << "Enter gift units: ";
        cin >> units;
        while (units < 1){
            cout << "Gift units must be at least 1" << endl;
            cout << "Enter gift units: ";
            cin >> units;
        }
    }
    void display(const Gift& theGift)
    {
        cout << "Gift Details:" << endl;
        cout << " Description: " << theGift.m_description << endl;
        cout << "       Price: " << theGift.m_price << endl;
        cout << "       Units: " << theGift.m_units << endl;
        
        if(theGift.m_wrapLayers > 0) {
            
            cout << "Wrap Layers: " << theGift.m_wrapLayers << endl;
            for(int i = 0; i<theGift.m_wrapLayers; i++) {
                
                cout << "Wrap #" << i+1 << " -> " << theGift.m_wrap[i].m_pattern<< endl;
                }
            } else {
            
            cout << "Unwrapped!" << endl;
        }
    }

    bool wrap(Gift& theGift)
    {
        bool result = true;
        
        if(theGift.m_wrapLayers > 0) {
            
            cout << "Gift is already wrapped!"<< endl;
            result = false;
        } else {
            
            cout << "Wrapping gifts..." << endl;
            cout << "Enter the number of wrapping layers for the Gift: ";
            cin >> theGift.m_wrapLayers;
            
            while(theGift.m_wrapLayers < 1) {
                
                cout << "Layers at minimum must be 1, try again."<< endl;
                cout << "Enter the number of wrapping layers for the Gift: ";
                cin >> theGift.m_wrapLayers;
            }
            
            theGift.m_wrap = new Wrapping[theGift.m_wrapLayers];
            
            for(int i = 0; i < theGift.m_wrapLayers; i++) {
                
                cout << "Enter wrapping pattern #" << i+1 << ": ";
                
                cin.width(MAX_WRAP + 1);
                cin >> theGift.m_wrap[i].m_pattern;
            }
        }
        return result;
    }

    bool unwrap(Gift& theGift)
    {
        bool result = true;
        
        if(theGift.m_wrapLayers < 1) {
            
            cout << "Gift isn't wrapped! Cannot unwrap." << endl;
            result = false;
        } else {
            
            cout << "Gift being unwrapped." << endl;
            
            theGift.m_wrapLayers = 0;
            delete [] theGift.m_wrap;
            theGift.m_wrap = nullptr;
        }
        return result;
    }

    void gifting(Gift& theGift)
    {
        cout << "Preparing a gift..." << endl;
        
        gifting(theGift.m_description);
        gifting(theGift.m_price);
        gifting(theGift.m_units);
        wrap(theGift);
    }
}
