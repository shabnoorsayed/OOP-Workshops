//
//  ReadWritable.cpp
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
#include "iostream"
#include <cstring>
#include <stdio.h>

using namespace std;
namespace sdds {

    ReadWritable::ReadWritable()
    {
        commaSeprated = false;
    }

    bool ReadWritable::isCsv()const
    {
        return commaSeprated;
    }

    void ReadWritable::setCsv(bool value)
    {
        commaSeprated = value;
    }

    ostream& operator<<(ostream& os, const ReadWritable& rw)
    {
        return rw.write(os);
    }

    istream& operator>>(istream& is, ReadWritable& rw)
    {
        rw.read(is);
        return is;
    }

    ReadWritable::~ReadWritable() {}
}
