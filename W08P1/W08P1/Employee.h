//
//  Employee.hpp
//  W08P1
//
//  Created by Shabnoor Sayed on 2020-07-23.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#ifndef Employee_h
#define Employee_h

#include <stdio.h>
#include <iostream>

namespace sdds {

    class Employee {
        
        const int MIN_HOUR;
        double salaryHour;
        
    protected:
        
        int getMinHour() const;
        double getSalaryHour() const;
        
    public:
        Employee(int minHour, double salaryHour);
        virtual std::ostream& display(std::ostream& out = std:: cout) const = 0;
        virtual double getSalary(int workedHour) const = 0;
        virtual ~Employee();
    };
    std::ostream& operator<<(std::ostream& os, const Employee& output);
}

#endif /* Employee_h */
