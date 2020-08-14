//
//  Doctor.hpp
//  W08P1
//
//  Created by Shabnoor Sayed on 2020-07-23.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#ifndef Doctor_h
#define Doctor_h

#include <iostream>
#include <iomanip>
#include "Employee.h"

namespace sdds {

    class Doctor : public Employee
    {
        
        char doc_type[33];
        bool specialist;
        
    public:
        Doctor(const char* d_type,double d_salary, int d_minHours, bool d_special = false);
        double getSalary(int workedHours) const;
        std::ostream& display(std::ostream& out = std:: cout) const;
    };
}

#endif /* Doctor_h */
