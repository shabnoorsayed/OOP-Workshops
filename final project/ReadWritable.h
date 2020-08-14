//
//  ReadWritable.hpp
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
#ifndef ReadWritable_h
#define ReadWritable_h

#include <stdio.h>
#include "Menu.h"
#include "iostream"
#include <cstring>

namespace sdds {

    class ReadWritable {
        bool commaSeprated;
    public:
        ReadWritable();
        virtual ~ReadWritable();
        bool isCsv()const;
        void setCsv(bool value);
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
    };
    std::ostream& operator<<(std::ostream& os, const ReadWritable& rw);
    std::istream& operator>>(std::istream& is, ReadWritable& rw);
}

#endif /* ReadWritable_h */
