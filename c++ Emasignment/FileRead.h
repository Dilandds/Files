//Trainee Header file

#ifndef MANAGEMENT_SYSTEM_FILEREAD_H
#define MANAGEMENT_SYSTEM_FILEREAD_H


#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include "RecordKeeping.h"
#include "SalariedEmployee.h"
#include "HourlyPaidEmployee.h"
#include "TraineeRecords.h"

class FileRead{
private:
    string filename;
    RecordKeeping r;
public:


    FileRead(string name);
    void ReadToHash();
    void ExtractInfoSalaried(string line);
    void ExtractInfoHourly(string line);
    void ExtractInfoTrainee(string line);

};



#endif //MANAGEMENT_SYSTEM_FILEREAD_H
