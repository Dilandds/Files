//Person Header file
#ifndef MANAGEMENT_SYSTEM_PERSON_H
#define MANAGEMENT_SYSTEM_PERSON_H
#include <string>
using namespace std;

class Person{
private:
    string name;
    int age;
    string id;
public:
    Person(string _name,int _age,string _id);
    void SetName(string _name);
    string GetName();
    void SetAge(int _age);
    int GetAge();
    void SetId(string _id);
    string GetId();

};

#endif //MANAGEMENT_SYSTEM_PERSON_H
