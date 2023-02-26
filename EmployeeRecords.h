

#ifndef MANAGEMENT_SYSTEM_EMPLOYEERECORDS_H
#define MANAGEMENT_SYSTEM_EMPLOYEERECORDS_H


#include "RecordKeeping.h"

class EmployeeRecords: public RecordKeeping{
private:
    map<string ,Employee *>::iterator itr3;
public:

    void ListAll1();
    bool IsHourlyPaid(Employee* object);
    bool IsSalaried(Employee* object);
    int GetDetails(string id);
    int DeleteRecord(string id);

};


#endif //MANAGEMENT_SYSTEM_EMPLOYEERECORDS_H
