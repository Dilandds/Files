//File Read class

#include "FileRead.h"


//constructor
FileRead::FileRead(string name){
    filename = name;
}
//Reading text file to the hash map
void FileRead::ReadToHash(){

    string test, Title;

    ifstream file (filename);
    int group=0;
    if (file.is_open()) {
        while (file >> test) {

            // check the title
            if (test == "Salaried") {
                // test is "Title:" so we need to save the movie title
                getline(file, Title);
                //cout << "\n EM-salaried" << movieName <<"\n";
                group = 1;

                continue;
                // check the title
            } else if(test == "Hourly") {
                getline(file, Title);
                //cout << "\n EM-hourly" << movieName << "\n";
                group = 2;
                continue;
                // check the title
            } else if(test == "Trainee"){
                getline(file, Title);
                //cout << "\n EM-reainee" << movieName;
                group = 3;
                continue;
                // When the title is Salaried
            }else if(group==1){
                ExtractInfoSalaried(test);
                //When the title is Hourly
            }else if(group==2){
                ExtractInfoHourly(test);
                //When the title is Trainee
            }else if(group==3){
                ExtractInfoTrainee(test);
            }

        }
        file.close();

    }
    else {
        std::cout << "unable to open file";
    }

}
//Extract salaried Employee details
void FileRead::ExtractInfoSalaried(string line){
    vector<string> v;
    char arr[line.length() + 1];
    strcpy(arr, line.c_str());
    char *ptr;
    ptr = strtok(arr, " , ");
    while (ptr != NULL)
    {
        v.push_back(ptr);
        ptr = strtok (NULL, " , ");
    }
    int _age = stoi(v[2]);
    float _salary = stof(v[3]);
    Employee*a= new SalariedEmployee (v[1],_age,v[0],_salary);
    //Insert Into the hash table
    r.Insert(a);

}
//Extract Hourly Employee Details
void FileRead::ExtractInfoHourly(string line){
    vector<string> v;
    char arr[line.length() + 1];
    strcpy(arr, line.c_str());
    char *ptr;
    ptr = strtok(arr, " , ");
    while (ptr != NULL)
    {
        v.push_back(ptr);
        ptr = strtok (NULL, " , ");
    }
    int _age = stoi(v[2]);
    float _rate =stof(v[3]);
    int _hours = stoi(v[4]);
    Employee*b =new HourlyPaidEmployee (v[1],_age,v[0],_rate,_hours);
    //Insert Into the hash table
    r.Insert(b);


}
//Extract Trainee Details
void FileRead::ExtractInfoTrainee(string line){
    vector<string> v;
    char arr[line.length() + 1];
    strcpy(arr, line.c_str());
    char *ptr;
    ptr = strtok(arr, " , ");
    while (ptr != NULL)
    {
        v.push_back(ptr);
        ptr = strtok (NULL, " , ");
    }
    int _age = stoi(v[2]);
    float _allowance =stof(v[3]);
    Trainee* t1=new Trainee (v[1],_age,v[0],v[4],_allowance);
    //Insert Into the hash table
    r.Insert(t1);

}
