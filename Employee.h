
#include "Person.h"
#ifndef MANAGEMENT_SYSTEM_EMPLOYEE_H
#define MANAGEMENT_SYSTEM_EMPLOYEE_H
#include <string>
using namespace std;

//Employee header file
class Employee:public Person{
public:
    Employee(string _name,int _age,string _id);
    virtual float  GetSalary() = 0;
    virtual void GetDetails() =0;
};


#endif //MANAGEMENT_SYSTEM_EMPLOYEE_H
