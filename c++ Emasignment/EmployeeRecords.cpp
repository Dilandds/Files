//
// Created by dilanw on 12/29/2022.
//

#include <iostream>
#include "EmployeeRecords.h"
#include "HourlyPaidEmployee.h"
#include "SalariedEmployee.h"


void EmployeeRecords::ListAll1() {
    //map<string ,Employee >::iterator itr3 = GetIterator();
    cout << "All Employees" << endl;
    cout << '\t' << "ID" << '\t' << "Name" << endl;
    cout << '\t' << "___________________________" << endl;
    for (itr3 = RecordKeeping::employee_records.begin(); itr3 != RecordKeeping::employee_records.end(); ++itr3) {
        cout << '\t' << itr3->first << '\t' << itr3->second->GetName() << '\n';
    }
}
//bool EmployeeRecords::IsHourlyPaid(Employee* object)
//{
//    HourlyPaidEmployee* number = dynamic_cast<HourlyPaidEmployee*>(object);
//    if (number == NULL)
//        return false;
//    return true;
//}
//bool EmployeeRecords::IsSalaried(Employee* object){
//    SalariedEmployee*number = dynamic_cast<SalariedEmployee*>(object);
//    if (number == NULL)
//        return false;
//    return true;
//}
int EmployeeRecords::GetDetails(string id){
    auto it = RecordKeeping::employee_records.find(id);

    if(it!=RecordKeeping::employee_records.end()){
        it->second->GetDetails();
//        if(IsSalaried((it->second))){
//            SalariedEmployee *s;
//            s=(SalariedEmployee*)(it->second);
//            cout << "Id Owner is a Salaried Employee" << endl;
//            cout <<"Id:"<< s->GetId() << endl;
//            cout <<"Name:"<< s->GetName()<< endl;
//            cout <<"Age:"<< s->GetAge() << endl;
//            cout <<"Salary:"<< s->GetSalary() << endl;
//            return 1;
//        }
//
//        if(IsHourlyPaid(it->second)){
//            HourlyPaidEmployee *s;
//            s = (HourlyPaidEmployee*)(it->second);
//            cout << "Id Owner is a Hourly Paid Employee" << endl;
//            cout << "id:"<< s->GetId() << endl;
//            cout << "name:"<<s->GetName() << endl;
//            cout << "age:"<< s->GetAge()<< endl;
//            cout << "salary:"<< s->GetSalary() << endl;
//            cout << "hours worked:"<<s->GetHoursWorked() << endl;
//            cout << "Rate:"<<s->GetHourlyRate() << endl;
//            return 1;
//        }
    } else{
        return 0;
    }
}
int EmployeeRecords::DeleteRecord(string id){
    int i=RecordKeeping::employee_records.erase(id);
    if(i==0){
        return 0;
    }else{
        cout << "Id Owner is a Employee, Record Deleted." << endl;
        return 1;
    }
}

