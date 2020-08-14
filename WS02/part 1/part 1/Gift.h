//
//  Gift.hpp
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


#ifndef SDDS_GIFT_H
#define SDDS_GIFT_H
#include <string>


namespace sdds
{
    const int MAX_DESC = 15;
    const double MAX_PRICE = 999.999;
    const int MAX_WRAP = 20;

    struct Wrapping
    {
        std :: string m_pattern;
    };

    struct Gift
    {
        char m_description[MAX_DESC];
        double m_price;
        int m_units;
        int m_wrapLayers;
        Wrapping* m_wrap = nullptr;
        
    };

    void gifting(char*);
    void gifting(double&);
    void gifting(int&);
    void display(const Gift& theGift);
    bool wrap(Gift& theGift);
    bool unwrap(Gift& theGift);
    void gifting(Gift& theGift);
}

#endif /* Gift_hpp */
