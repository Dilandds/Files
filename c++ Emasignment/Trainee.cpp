//Trainee class
#include "Trainee.h"


//constructor
Trainee::Trainee(string _name,int _age,string _id,string _duration,float _allowance): Person(_name,_age,_id){
    training_duration = _duration;
    monthly_allowance = _allowance;
}
//Get the duration
string Trainee::GetTrainingDuration(){
    return training_duration;
}
//Get the allowance
float Trainee::GetAllowance(){
    return monthly_allowance;
}

