//Salaried Employee class
#include <iostream>
#include "SalariedEmployee.h"
#include <string>
//Constructor
SalariedEmployee::SalariedEmployee(string _name,int _age,string _id,float _salary): Employee(_name,_age,_id){
    salary =_salary;
}
//virtual function implementation
float SalariedEmployee::GetSalary(){
    return salary;
}
//virtual function implementation
void SalariedEmployee::GetDetails() {
    cout << "Id Owner is a Salaried Employee" << endl;
    cout <<"Id:"<< this->GetId() << endl;
    cout <<"Name:"<< this->GetName()<< endl;
    cout <<"Age:"<< this->GetAge() << endl;
    cout <<"Salary:"<< this->GetSalary() << endl;
}
