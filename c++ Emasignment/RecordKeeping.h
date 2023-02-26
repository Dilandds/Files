//Record keeping header file

#ifndef MANAGEMENT_SYSTEM_RECORDKEEPING_H
#define MANAGEMENT_SYSTEM_RECORDKEEPING_H


#include <map>
#include "Trainee.h"
#include "Employee.h"

class RecordKeeping{
private:
    map<string ,Employee* >::iterator itr;
    map<string ,Trainee* >::iterator itr1;
protected:
     static map<string ,Employee*> employee_records;
     static map<string ,Trainee*> trainee_records;
public:
    void Insert(Employee* e);

    void Insert(Trainee* p);
    map<string ,Employee*> GetEmployeeRecords();
    map<string ,Trainee*> GetTraineeRecords();
    map<string ,Employee* >::iterator GetIterator();
    void ListAll();

    void ListMonthlyPay();

    void TotalPay();

    int GetDetailsEmployee;

    void SearchDetails();

};






#endif //MANAGEMENT_SYSTEM_RECORDKEEPING_H
