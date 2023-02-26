//class Hourly paid employees
#include <string>
#include "HourlyPaidEmployee.h"
#include <iostream>
//constructor
HourlyPaidEmployee::HourlyPaidEmployee(string _name,int _age,string _id,float _rate,int _hours): Employee(_name,_age,_id){
    hourly_rate = _rate;
    hours_worked = _hours;
}
//Get hourly paid rate
float HourlyPaidEmployee::GetHourlyRate(){
    return hourly_rate;
}
//Get hours worked
int HourlyPaidEmployee::GetHoursWorked(){
    return hours_worked;
}
//Virtual function implementation
float HourlyPaidEmployee::GetSalary(){
    return hourly_rate* hours_worked;
}
//Virtual function implementation
void HourlyPaidEmployee::GetDetails() {
    cout << "Id Owner is a Hourly Paid Employee" << endl;
    cout << "id:"<< this->GetId() << endl;
    cout << "name:"<< this->GetName() << endl;
    cout << "age:"<< this->GetAge()<< endl;
    cout << "salary:"<< this->GetSalary() << endl;
    cout << "hours worked:"<< this->GetHoursWorked() << endl;
    cout << "Rate:"<< this->GetHourlyRate() << endl;
}


