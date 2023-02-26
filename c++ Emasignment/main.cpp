#include <iostream>
#include <map>
using namespace std;
#include <fstream>
#include<vector>
#include <cstring>
#include <algorithm>
#include "Person.h"
#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyPaidEmployee.h"
#include "Trainee.h"
#include "RecordKeeping.h"
#include "EmployeeRecords.h"
#include "TraineeRecords.h"
#include "FileRead.h"

//static hash maps
map<string ,Employee*> RecordKeeping::employee_records;
map<string ,Trainee*> RecordKeeping::trainee_records;

//display menu
void display()
{
    cout << "\ncommand [list_all] to list all the employee \n";
    cout << "command [list_monthly_pay] to List the monthly pay amount of all the employees and trainees\n";
    cout << "command [get_total_pay] to Get the total number of employees and trainees along with their total pay\n";
    cout << "command [get_details <id>] to  Get the full details of an employee/trainee when given employee id/trainee id\n";
    cout << "command [remove <id>] to Remove an employee/trainee when given employee id/trainee id.\n";
    cout << "command [exit] to Exit from software";
    cout << "command [help] to get instructions on how to use this system\n";
}
//split a text line from a given character and add to a vector
size_t split(const string &txt,vector<std::string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

    return strs.size();
}
//string comparison
int case_insensitive_match(string s1, string s2) {
    //convert s1 and s2 into lower case strings
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    if(s1.compare(s2) == 0)
        return 1; //The strings are same
    return 0; //not matched
}
//handle the menu ( get data from tables and display)
void menu(){
    FileRead r1("t.txt");
    r1.ReadToHash();
    RecordKeeping r;
    EmployeeRecords er;
    TraineeRecords tr;
    //check for given arguments
    vector<string > v1 = {"list_all","list_monthly_pay","get_total_pay","get_details","remove","exit","help"};
    vector<string> v;
    bool ip= true;
    while(ip){
        display();
        cout << "Enter the command:";
        string input;
        getline(cin,input);
        //cout << input;
        split(input,v,' ');
        int i;
        int j=-1;
        for( i=0;i<v1.size();i++){
            if(case_insensitive_match(v[0],v1[i])){
                j=i;
                break;
            }
        }
        //handling errors and identify given arguments
        if(j==3 || j==4 ){
            if(v.size()!=2) {
                j = -2;//wrong number of arguments
            }else{
                if(v[1].size()>2) {
                    string sub = v[1].substr(0, 2);
                    string sub1 = v[1].substr(2, v[1].size() - 2);
                    string t1 = "EM";
                    string t2 = "TR";


                    int id = stoi(sub1);
                    int a = sub.compare(t1);
                    int b = sub.compare(t2);
                    if ((sub!="EM")&&(sub!="TR")) {
                        j = -9;//Id is wrong
                    } else if (sub=="EM" && ((0>=id)||(100<id))) {
                        j = -4;  //ID out of range
                    } else if (sub=="TR"&& ((0 >= id)||(50 < id))) {
                        j = -5; //ID out of range for trinee
                    }
                }else{
                    j=-6 ;//id is wrong
                }
            }
        }
        if(j==0 or j==1 or j==2 or j==5 or j==6) {
            if (v.size() != 1) {
                j = -2;//wrong number of arguments
            }
        }
        //using j call the functions
        switch (j) {
            case 0:{
                r.ListAll();
                break;
            }
            case 1:{
                r.ListMonthlyPay();
                break;
            }
            case 2:{
                r.TotalPay();
                break;
            }
            case 3:{
                //r.table.SearchKey(v[1]);
                string sub = v[1].substr(0, 2);
                int a=0;
                int b=0;
                if(sub=="TR"){
                    b=tr.GetDetails(v[1]);

                }else if(sub=="EM"){
                    a=er.GetDetails(v[1]);
                }
                if(a==0 && b==0){
                    cout << "No Record with given ID" << endl;
                }
                break;
            }
            case 4:{
                int a =er.DeleteRecord(v[1]);
                int b=tr.DeleteRecord(v[1]);
                if(a==0 && b==0){
                    cout << "No Record with given ID" << endl;
                }
                break;
            }
            case 5:{
                ip = false;
                break;
            }
            case 6:{
                break;
            }
            case -2:{
                cout << "Wrong number of arguments" << endl;
                break;
            }
            case -9:{
                cout << "Given Id is incorrect" << endl;
                break;
            }
            case -4:{
                cout << "Id out of range(0-100)" << endl;
                break;
            }
            case -5:{
                cout << "Id out of range(0-50)" << endl;
                break;
            }
            case -6:{
                cout << "Id is wrong" << endl;
                break;
            }


        }
    }
}

int main() {
    menu();

    return 0;


}
