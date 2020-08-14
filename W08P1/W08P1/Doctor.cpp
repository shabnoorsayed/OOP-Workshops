//
//  Doctor.cpp
//  W08P1
//
//  Created by Shabnoor Sayed on 2020-07-23.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#include "Doctor.h"
#include "Employee.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
namespace sdds {

    Doctor::Doctor(const char* d_type,double d_salary, int d_minHours, bool d_special):Employee(d_minHours, d_salary)
    {
        
            specialist = d_special;
            strcpy(doc_type, d_type);
    }

    double Doctor::getSalary(int workedHours) const
    {
        
        double d_salary = 0.0;
        int d_hours = 0;
        d_salary = Employee::getSalaryHour();
        d_hours = Employee::getMinHour();
        if(workedHours <= d_hours) {
            d_salary *= workedHours;
            if(specialist == true) {
                d_salary = (Employee::getSalaryHour() * workedHours) + 2000;
            }
        }
        if(workedHours > d_hours) {
            int overtime = (Employee::getSalaryHour()* (1.5)) * (workedHours - d_hours);
            d_salary = Employee::getSalaryHour() * d_hours + overtime;
            if(specialist == true) {
                int overtime = ((Employee::getSalaryHour()* (1.5)) * (workedHours - d_hours));
                d_salary = (Employee::getSalaryHour() * d_hours + overtime) + 2000;
            }
        }
        
        return d_salary;
    }

    std::ostream& Doctor::display(std::ostream& out) const
    {
        out <<"Doctor" << endl;
        if (specialist) {
            out << right << setw(16) <<"Type: " << doc_type << " (specialist)" << endl;
            out << right << setw(16) << "Pay Rate: " << getSalaryHour() << endl;
            out << right << setw(16) << "Min Hours: " << getMinHour() << endl;
        }else {
            out << right << setw(16) << "Type: " << doc_type << endl;
            out << right << setw(16) << "Pay Rate: " << getSalaryHour() << endl;
            out << right << setw(16) << "Min Hours: " << getMinHour() << endl;
        }
        return out;
    }

}
