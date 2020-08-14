//
//  Engineer.hpp
//  W08P1
//
//  Created by Shabnoor Sayed on 2020-07-24.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#ifndef Engineer_h
#define Engineer_h

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Employee.h"

namespace sdds {

    class Engineer : public Employee {
        
        int e_level;
    public:
        Engineer(double e_salary, int level, int e_hours = 30);
        double getSalary(int workedHours) const;
        std::ostream& display(std::ostream& out = std:: cout) const;
    };
}
#endif /* Engineer_h */
