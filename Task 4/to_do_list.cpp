#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void Add_task();
void View_task();
void Task_status();
void Delete_task();

int main() {
    while(true){
        int choice;
        cout << "Please enter\n1::Add task  2::View task\n3::Task status  4::Remove Task\n5::Exit\nEnter::";
        cin >> choice;
        cin.ignore();
        if(choice == 1){
            Add_task();
        }
        else if(choice == 2){
            View_task();
        }
        else if(choice == 3){
            Task_status();
        }
        else if(choice == 4){
            Delete_task();
        }
        else if(choice == 5){
            exit(0);
        }
        else {
            cout << "Wrong input." << endl;
        }
    }
}

void Add_task(){
    fstream file("to_do_list.txt",ios::in|ios::out|ios::app);
    if(file.is_open()){
        string task;
        string status;
        
        cout << "Task::";
        getline(cin,task);
        cout << "Status::";
        getline(cin,status);
        file << task << endl;
        file << status << endl;
    }
    else {
        cout << "Could not open the file." << endl;
    }
    file.close();
}

void View_task(){
    fstream file("to_do_list.txt",ios::in|ios::out|ios::app);
    string line;
    getline(file,line);
    int count = 1;
    cout << endl;
    while(!line.empty()){
        cout << count << " | " << line;
        getline(file,line);
        cout << " | " << line << endl;
        getline(file,line);
        count++;
    }
    cout << endl;
    if(!line.empty()) {
        cout << "!!!No Task Left!!!" << endl << endl;
    }
    file.close();
}

void Task_status(){
    fstream file("to_do_list.txt",ios::in|ios::out|ios::app);
    string search;
    cout << "Which task do you want to update? :: ";
    getline(cin,search);
    fstream temp("temp.txt",ios::in|ios::out|ios::app);
    string line;
    bool check=true;
    getline(file,line);
    while(!line.empty()){
        if(search == line) {
            temp << line << endl;
            getline(file,line);
            // line = "complete";
            temp << "complete" << endl;
            check = false;
            cout << "!!!Done!!!" << endl;
            getline(file,line);
        }
        else{
            temp << line << endl;
            getline(file,line);
            temp << line << endl;
            getline(file,line);
        }
    }
    if(check){
        cout << "!!!Task not within the list!!!" << endl;
    }
    file.close();
    temp.close();
    remove("to_do_list.txt");
    rename("temp.txt","to_do_list.txt");
}

void Delete_task(){
    fstream file("to_do_list.txt",ios::in|ios::out|ios::app);
    string search;
    cout << "Which task do you want to delete? :: ";
    getline(cin,search);
    fstream temp("temp.txt",ios::in|ios::out|ios::app);
    string line;
    bool check=true;
    getline(file,line);
    while(!line.empty()){
        if(search == line) {
            check = false;
            getline(file,line);
            getline(file,line);
            cout << "!!!Done!!!" << endl;
        }
        else{
            temp << line << endl;
            getline(file,line);
            temp << line << endl;
            getline(file,line);
        }
    }
    if(check){
        cout << "!!!Task not within the list!!!" << endl;
    }
    file.close();
    temp.close();
    remove("to_do_list.txt");
    rename("temp.txt","to_do_list.txt");
}