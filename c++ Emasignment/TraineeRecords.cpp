//Trainee Records class

#include "TraineeRecords.h"

//List all trainee
void TraineeRecords::ListAll(){
    cout << "All Trainees" << endl;
    cout << '\t' << "ID" << '\t' << "Amount"<<endl;
    cout << '\t' << "_____________________" << endl;
    for (itr1 = RecordKeeping::GetTraineeRecords().begin(); itr1 != RecordKeeping::GetTraineeRecords().end(); ++itr1) {
        cout << '\t' << itr1->first << '\t' << itr1->second->GetName() << '\n';
    }
}
//Get details of a Trainee when ID is given
int TraineeRecords::GetDetails(string id) {
    auto it = RecordKeeping::trainee_records.find(id);

    if (it != RecordKeeping::trainee_records.end()) {
        cout << "Id owner is a trainee" << endl;
        cout << "Id:" << it->second->GetId() << endl;
        cout << "Name:" << it->second->GetName() << endl;
        cout << "Age:" << it->second->GetAge() << endl;
        cout << "Training Duration:" << it->second->GetTrainingDuration() <<"months"<< endl;
        cout << "Get allowance:" << it->second->GetAllowance() << endl;
        return 1;
    } else{
        return 0;
    }
}
//Delete record of a trainee when the ID is given
int TraineeRecords::DeleteRecord(string id){
    int i=RecordKeeping::trainee_records.erase(id);
    if(i==0){
        return 0;
    }else{
        cout << "Id owner is a trainee, Record Deleted!" << endl;
        return 1;
    }
}

