//
//  Employee.cpp
//  W08P1
//
//  Created by Shabnoor Sayed on 2020-07-23.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#include "Employee.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
namespace sdds {

    int Employee::getMinHour() const
    {
        return MIN_HOUR;
    }

    double Employee::getSalaryHour() const
    {
        return salaryHour;
    }

    Employee::Employee(const int minHour, double salary_hour) : MIN_HOUR(minHour), salaryHour(salary_hour)
    {}
     
    std::ostream& Employee::display(std::ostream& out) const
    {
        return cout;
    }

    Employee::~Employee()
    {}

    std::ostream& operator<<(ostream& os, const Employee& output)
    {
        output.display(os);
        return os;
    }
}
