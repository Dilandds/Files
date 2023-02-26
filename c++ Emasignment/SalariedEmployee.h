//Salaried Employee header
#include "Employee.h"
#ifndef MANAGEMENT_SYSTEM_SALARIEDEMPLOYEE_H
#define MANAGEMENT_SYSTEM_SALARIEDEMPLOYEE_H

class SalariedEmployee:public Employee{
private:
    float salary;
public:
    SalariedEmployee(string _name,int _age,string _id,float _salary);
    float GetSalary();
    void GetDetails();

};


#endif //MANAGEMENT_SYSTEM_SALARIEDEMPLOYEE_H
