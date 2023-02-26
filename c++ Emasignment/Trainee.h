//Trainee header

#ifndef MANAGEMENT_SYSTEM_TRAINEE_H
#define MANAGEMENT_SYSTEM_TRAINEE_H
#include "Person.h"

class Trainee:public Person{
private:
    string training_duration;
    float monthly_allowance;
public:
    Trainee(string _name,int _age,string _id,string _duration,float _allowance);
    string GetTrainingDuration();
    float GetAllowance();
};

#endif //MANAGEMENT_SYSTEM_TRAINEE_H
