//Hourly paid employee header file
#include "Employee.h"
#ifndef MANAGEMENT_SYSTEM_HOURLYPAIDEMPLOYEE_H
#define MANAGEMENT_SYSTEM_HOURLYPAIDEMPLOYEE_H


class HourlyPaidEmployee:public Employee{
private:
    float hourly_rate;
    int hours_worked;
public:
    HourlyPaidEmployee(string _name,int _age,string _id,float _rate,int _hours);
    float GetHourlyRate();
    int GetHoursWorked();
    float GetSalary();
    void GetDetails();


};


#endif //MANAGEMENT_SYSTEM_HOURLYPAIDEMPLOYEE_H
