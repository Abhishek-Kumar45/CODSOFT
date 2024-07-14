#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct tasks {
    string description;
    bool isComplete;
};

void display() {
    cout<<"\nTo-Do List Menu:"<<endl;
    cout<<"1. Add a task"<<endl;
    cout<<"2. View tasks"<<endl;
    cout<<"3. Delete a task"<<endl;
    cout<<"4. Mark a task as complete"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter your choice: ";
}

void addTask(vector<tasks> &tasks) {
    cout<<"Enter task description :"<<endl;

    string taskDescription;
    cin.ignore();
    getline(cin, taskDescription);

    tasks.push_back({taskDescription, false});
    cout<<"Task added Successfully"<<endl;
}

void showTasks(vector<tasks> &tasks) {
    if(tasks.size() == 0) {
        cout<<"No tasks to show"<<endl;
        return;
    }

    cout<<"To-Do List:"<<endl;
    for(int i=0; i<tasks.size(); i++) {
        cout<<"Task "<<i+1<<" : "<<tasks[i].description;
        if(tasks[i].isComplete) {
            cout<<" COMPLETED"<<endl;
        }
        cout<<endl;
    } 
}

void deleteTask(vector<tasks> &tasks) {
    if(tasks.size() == 0) {
        cout<<"No Tasks to Delete"<<endl;
        return;
    }

    showTasks(tasks);
    int idx;
    cout<<"Enter the Task Number to be Deleted"<<endl;
    cin>>idx;

    if(idx < 1 || idx > tasks.size()) {
        cout<<"Invalid Task Number"<<endl;
    }
    else {
        tasks.erase(tasks.begin() + idx - 1);
        cout<<"Task "<<idx<<" Deleted Successfully!"<<endl;
    }
}

void markComplete(vector<tasks> &tasks) {
    if(tasks.size() == 0) {
        cout<<"No tasks to mark as complete"<<endl;
    }

    showTasks(tasks);
    int idx;
    cout<<"Enter the Task number to be mark as completed"<<endl;
    cin>>idx;

    if(idx<1 || idx>tasks.size()) {
        cout<<"Invalid task number."<<endl;
    } 
    else {
        tasks[idx - 1].isComplete = true;
        cout<<"Task "<<idx<<" marked as completed!"<<endl;
    }
}

int main() {
    vector<tasks> tasks;

    int choice;
    
    while(1) {
        display();
        cin>>choice;

        switch(choice) {
            case 1: addTask(tasks);
                    break;

            case 2: showTasks(tasks);
                    break;
                    
            case 3: deleteTask(tasks);
                    break;

            case 4: markComplete(tasks);
                    break;

            case 5: cout<<"Exiting the To-Do List applicattion"<<endl;
                    return 0;

            default : cout<<"Invalid choice, Please Try Again"<<endl;
        }
    }
}