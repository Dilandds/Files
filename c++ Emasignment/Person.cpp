
//Person class
#include <string>
#include "Person.h"
using namespace std;


Person::Person(string _name,int _age,string _id){
    name = _name;
    age = _age;
    id = _id;
}
void Person::SetName(string _name){
    name = _name;
}
string Person::GetName(){
    return name;
}
void Person::SetAge(int _age){
    age = _age;
}
int Person::GetAge(){
    return age;
}
void Person::SetId(string _id){
    id = _id;
}
string Person::GetId(){
    return id;
}

