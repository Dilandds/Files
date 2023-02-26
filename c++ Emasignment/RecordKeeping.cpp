
//Record Keeping Header file
#include <iostream>
#include "RecordKeeping.h"


//Insert Employee into the record keeping
void RecordKeeping::Insert(Employee* e){

    employee_records.insert(pair<string, Employee*>(e->GetId(), e));
}
//Insert Trainee into the record Keeping
void RecordKeeping::Insert(Trainee* p){
    trainee_records.insert(pair<string, Trainee*>(p->GetId(), p));
}
//Get employee records
map<string ,Employee*> RecordKeeping::GetEmployeeRecords(){
    return employee_records;
}
//Get trainee Records
map<string ,Trainee*> RecordKeeping::GetTraineeRecords(){
    return trainee_records;
}

//List all records
void RecordKeeping::ListAll(){

    cout << "All Employees" << endl;
    cout << '\t' << "ID" << '\t' << "Name"<<endl;
    cout << '\t' << "___________________________" << endl;
    for (itr = employee_records.begin(); itr != employee_records.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second->GetName() << '\n';
    }
    //map<string ,Trainee >::iterator itr1;
    cout << "All Trainees" << endl;
    cout << '\t' << "ID" << '\t' << "Name"<<endl;
    cout << '\t' << "_____________________" << endl;
    for (itr1 = trainee_records.begin(); itr1 != trainee_records.end(); ++itr1) {
        cout << '\t' << itr1->first << '\t' << itr1->second->GetName() << '\n';
    }
}
//List all monthly payments of employees
void RecordKeeping::ListMonthlyPay(){
    //map<string , Employee>::iterator itr;
    cout << "Employees Monthly Pay" << endl;
    cout << '\t' << "Name" << '\t' << "Amount"<<endl;
    cout << '\t' << "____________________" << endl;
    for (itr = employee_records.begin(); itr != employee_records.end(); ++itr) {
        cout << '\t' << itr->second->GetName() << '\t' << itr->second->GetSalary() << '\n';
    }
    //map<string , Trainee>::iterator itr1;
    cout << "\n"<<"Trainee Monthly Pay" << endl;
    cout << '\t' << "Name" << '\t' << "Amount"<<endl;
    cout << '\t' << "____________________" << endl;
    for (itr1 = trainee_records.begin(); itr1 != trainee_records.end(); ++itr1) {
        cout << '\t' << itr1->second->GetName() << '\t' << itr1->second->GetAllowance() << '\n';
    }

}
//Count the total payment
void RecordKeeping::TotalPay(){
    float employee_total_salary=0;
    for (itr = employee_records.begin(); itr != employee_records.end(); ++itr) {
        //cout << '\t' << itr->second.GetName() << '\t' << itr->second.GetSalary() << '\n';
        //employee_count=employee_count+1;
        employee_total_salary=employee_total_salary+itr->second->GetSalary();
    }
    cout << "Total employees:" << employee_records.size() << endl;
    cout << "Total salary:" << employee_total_salary << endl;

    float trainee_total_salary=0;
    for (itr1 = trainee_records.begin(); itr1 != trainee_records.end(); ++itr1) {
        //cout << '\t' << itr1->second.GetName() << '\t' << itr1->second.GetAllowance() << '\n';
        //trainee_count=trainee_count+1;
        trainee_total_salary=trainee_total_salary+itr1->second->GetAllowance();
    }
    cout << "\n";

    cout << "Total Trainees:" << trainee_records.size()<< endl;
    cout << "Total salary:" << trainee_total_salary << endl;
}






