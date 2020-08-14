//
//  Engineer.cpp
//  W08P1
//
//  Created by Shabnoor Sayed on 2020-07-24.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#include "Engineer.h"
#include "Doctor.h"
#include "Employee.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
namespace sdds {

    Engineer::Engineer(double e_salary, int level, int e_hours) : Employee(e_hours, e_salary)
    {
        
        e_level = level;
        
    }

    double Engineer::getSalary(int workedHours) const
    {
        
        double e_salary = 0.0;
        int e_hour = 30;
        
        e_salary = (Employee::getSalaryHour()* workedHours) + (40 * e_level);
        
        if(workedHours < e_hour) {
            e_salary = e_salary * 0.8;
        } 
        return e_salary;
    }

    ostream& Engineer::display(std::ostream& out) const
    {
        out <<"Engineer" << endl;
        out << right << setw(20) <<"Level: " << e_level << endl;
        out << right << setw(20) << "Pay Rate: " << getSalaryHour() << endl;
        out << right << setw(20) << "Min Hours: " << getMinHour() << endl;
        return out;
    }
    
}
