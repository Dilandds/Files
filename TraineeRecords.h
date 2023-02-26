//Trainee Records header file

#ifndef MANAGEMENT_SYSTEM_TRAINEERECORDS_H
#define MANAGEMENT_SYSTEM_TRAINEERECORDS_H


#include <iostream>
#include "RecordKeeping.h"

class TraineeRecords: public RecordKeeping{
private:
    map<string ,Trainee* >::iterator itr1;
public:
    void ListAll();
    int GetDetails(string id);
    int DeleteRecord(string id);
};


#endif //MANAGEMENT_SYSTEM_TRAINEERECORDS_H
