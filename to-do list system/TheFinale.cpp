#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX_TASKS 100
string mails[100] = { "hossam@gmail", "adly@yahoo", "hamid@gmail" };
string passwords[100] = { "hossam123", "adly432", "hamid2005" };
string names[100] = { "Hossam", "Adly", "AbdulHamed" };
string signedin[100];
string usercheck;
int arraycounter = 3;
int counter = 0;
int usernum;

struct date
{
    int day, month, year;
};

struct Task
{
    string description;
    bool completed;
    int priority;
    date due_date;
};

struct users {
    string name;
    string username;
    string pass;
    Task tasks[MAX_TASKS];
    int taskCount = 0;
};

users use[100];
int userscounter = 0;


int main_menu();
void add_task(Task tasks[], int& taskCount);
void log_in();
void log_in_new();
void display_tasks(Task tasks[], int taskCount);
void mark_task_as_complete();
int edit_task();
void search();
void delete_task();

int main()
{
    bool login = true;
    int choice;
    char choice_again;
    bool cont=true;
    do
    {
        if (login)
        {
            log_in();
            use[userscounter].name = names[usernum];
            use[userscounter].pass = passwords[usernum];
            use[userscounter].username = mails[usernum];
            login = false;
        }
        choice = main_menu();
        switch (choice)
        {
        case 1:
            do{
                add_task(use[userscounter].tasks,use[userscounter].taskCount);
                cout<<"Do you want to add another task? (y/n)";
                cin>>choice_again;
            }while(choice_again=='y'||choice_again=='Y');
           break;
        case 2:
            display_tasks(use[userscounter].tasks, use[userscounter].taskCount);
            break;
        case 3:
            mark_task_as_complete();
            break;
        case 4:
            edit_task();
            break;
        case 5:
            search();
            break;
        case 6:
            delete_task();
            break;
        case 7:
            cout << "loging out.\n";
            log_in_new();
            continue;
        case 0:
            cout << "Thank you for using the to-do task organizer 3000." << endl;
            cont=false;
            break;
        default:
            cout << "ERROR!!! Invalid choice. Please try again." << endl;
            break;
        }
        if(cont==false){
            break;
        }
    } while (true);
}

void log_in() {
    cout << "\t" << "\t" << "*****login page*****" << endl << endl;
    string name, email, password, password1, choice;
    cout << "do you already have an account? yes/no: ";
    cin >> choice;
    if (choice == "no" || choice == "No") {
        cout << "--------------------------------------------------------------------\n";
        cout << "\t" << "\t" << "create a user" << endl << endl;
        cout << "enter your name: ";
        for (arraycounter; arraycounter < 100;) {
            cin >> names[arraycounter];
            break;
        }
        bool checkuser = true;
        do {
            checkuser = true;
            cout << "Enter your email: ";
            cin >> usercheck;

            for (int u = 0; u < 3; ++u) {
                if (usercheck == mails[u]) {
                    checkuser = false;
                    break;
                }
            }

            if (checkuser == false) {
                cout << "User already exists!" << endl;
            }
            else {
                mails[arraycounter] = usercheck;
            }
            usercheck.erase();
        } while (checkuser == false);
        cout << "enter password: ";
        for (arraycounter; arraycounter < 100;) {
            cin >> passwords[arraycounter];
            break;
        }
        do {
            cout << "re-enter your password: ";
            cin >> password;
            if (password != passwords[arraycounter]) {
                cout << "password is incorrect please cheack it :(" << endl;
                password.erase();
            }
            else
                break;
        } while (password != passwords[arraycounter]);
        
        cout << "\t" << "\t" << "user created successfully!!!" << endl << endl;
        arraycounter++;
    }
    cout << "--------------------------------------------------------------------\n";
    cout << "\t" << "\t" << "Log-in" << endl;
    bool check = false;
    do {
        cout << "Enter your email: ";
        cin >> email;
        cout << "Enter password: ";
        cin >> password1;
        for (int i = 0; i < 100; ++i) {
            if (email == mails[i] && password1 == passwords[i]) {
                check = true;
                signedin[counter]=mails[i];
                counter++;
                usernum = i;
                break;
            }
        }
        if (check == false) {
            cout << "please enter correct username and password" << endl;
        }

    } while (!check);
    
    cout << "\t" << "\t" << "Welcome " << names[usernum] << endl;
    cout << "--------------------------------------------------------------------\n";
}

void log_in_new(){
    userscounter++;
        cout << "\t" << "\t" << "*****login page*****" << endl << endl;
    string name, email, password, password1, choice;
    cout << "do you already have an account? yes/no: ";
    cin >> choice;
    if (choice == "no" || choice == "No") {
        cout << "--------------------------------------------------------------------\n";
        cout << "\t" << "\t" << "create a user" << endl << endl;
        cout << "enter your name: ";
        for (arraycounter; arraycounter < 100;) {
            cin >> names[arraycounter];
            break;
        }
        bool checkuser = true;
        do {
            checkuser = true;
            cout << "Enter your email: ";
            cin >> usercheck;

            for (int u = 0; u < 3; ++u) {
                if (usercheck == mails[u]) {
                    checkuser = false;
                    break;
                }
            }

            if (checkuser == false) {
                cout << "User already exists!" << endl;
            }
            else {
                mails[arraycounter] = usercheck;
            }
            usercheck.erase();
        } while (checkuser == false);
        cout << "enter password: ";
        for (arraycounter; arraycounter < 100;) {
            cin >> passwords[arraycounter];
            break;
        }
        do {
            cout << "re-enter your password: ";
            cin >> password;
            if (password != passwords[arraycounter]) {
                cout << "password is incorrect please cheack it :(" << endl;
                password.erase();
            }
            else
                break;
        } while (password != passwords[arraycounter]);
        
        cout << "\t" << "\t" << "user created successfully!!!" << endl << endl;
        arraycounter++;
    }
    cout << "--------------------------------------------------------------------\n";
    cout << "\t" << "\t" << "Log-in" << endl;
    bool check = false;
    do {
        cout << "Enter your email: ";
        cin >> email;
        cout << "Enter password: ";
        cin >> password1;
        for (int i = 0; i < 100; ++i) {
            if (email == mails[i] && password1 == passwords[i]) {
                check = true;
                signedin[counter]=mails[i];
                counter++;
                usernum = i;
                break;
            }
        }
        if (check == false) {
            cout << "please enter correct username and password" << endl;
        }

    } while (!check);
    for(int h=0;h<100;++h){
        if (email==signedin[h]){
            userscounter=h;
            break;
        }
        else{
            userscounter++;
        }
    }
    
    cout << "\t" << "\t" << "Welcome " << names[usernum] << endl;
    cout << "--------------------------------------------------------------------\n";
}

int main_menu()
{
    int ans;
    cout << "\n\t==================================\n\t\t**Main Menu\n\t==================================";
    cout << "\n1 Add task" << endl
        << "2 Display task" << endl
        << "3 Mark task(s) as complete" << endl
        << "4 Edit task" << endl
        << "5 search" << endl
        << "6 delete task" << endl
        << "7 log out" << endl
        << "0 Exit" << endl;
    cout << "Enter your answer: ";
    cin >> ans;
    return ans;
}

void add_task(Task tasks[], int& taskCount) //**hossam**//
{
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    cout << "Enter priority level (1-5, higher = more important): ";
    while (true)
    {
        cin >> newTask.priority;
        if (newTask.priority >= 1 && newTask.priority <= 5)
            break;
        cout << "ERROR!!! invalid priority level, please eneter again: ";
    }
    cout << "please enter overdue date in (DD-MM-YYYY)FORMAT" << endl;
    cout << "enter Day (from 1 to 31): ";
    while (true)
    {
        cin >> newTask.due_date.day;
        if (newTask.due_date.day >= 1 && newTask.due_date.day <= 31)
            break;
        cout << "ERROR!!! enter a valid day (from 1 to 31): ";
    }
    cout << "enter month (from 1 to 12): ";
    while (true)
    {
        cin >> newTask.due_date.month;
        if (newTask.due_date.month >= 1 && newTask.due_date.month <= 12)
            break;
        cout << "ERROR!!! enter a valid month (from 1 to 12): ";
    }
    cout << "enter year: ";
    while (true)
    {
        cin >> newTask.due_date.year;
        if (newTask.due_date.year >= 2024)
            break;
        cout << "ERROR!!! enter a proper year :)" << endl;
    }
    tasks[taskCount] = newTask;
    taskCount++;

    cout << "Task added successfully!! :)" << endl;
}
// to display tasks in order *hamid*
bool compareTasks(const Task& t1, const Task& t2)
{
    return t1.priority > t2.priority;
}

void display_tasks(Task tasks[], int taskCount)
{
    if (taskCount == 0)
    {
        cout << "No tasks to display." << endl;
        return;
    }
    sort(tasks, tasks + taskCount, compareTasks);
    cout << "\nTask List:\n"
        << endl;
    cout << "Tasks to be done(not completed):\n\n";
    for (int i = 0; i < taskCount; i++)
    {
        if (!tasks[i].completed)
        {
            cout << "Task " << (i + 1) << ":" << endl
                << endl;
            cout << "Description: " << tasks[i].description << endl;
            cout << "Priority: " << tasks[i].priority << endl;
            // needs to be modified waiting for hoss
            cout << "Overdue date is : " << tasks[i].due_date.day << "/" << tasks[i].due_date.month << "/" << tasks[i].due_date.year;
            cout << endl
                << endl;
        }
        cout << "=====================\n";
    }
    cout << "\n=============================\n";
    cout << "Completed tasks :\n";
    for (int i = 0; i < taskCount; i++)
    {
        if (tasks[i].completed)
        {
            cout << "Task " << (i + 1) << ":" << endl
                << endl;
            cout << "Description: " << tasks[i].description << endl;
            cout << "Priority: " << tasks[i].priority << endl;
            cout << "Overdue date is : " << tasks[i].due_date.day << "/" << tasks[i].due_date.month << "/" << tasks[i].due_date.year;
            cout << endl
                << endl;
        }
    }
}

void search()
{
    char con;
    do
    {
        string tempSearch;
        int tempNum, tempPriorty, ans;

        cout << "\n\nEnter what you want to search about:\n1 despcription\n2 proirty level\n3 task no.\n\n ";
        cout << "Enter answer: ";
        cin >> ans;
        bool found = false;
        switch (ans)
        {
        case 1:
            cout << "enter description: ";
            cin.ignore();
            getline(cin, tempSearch);
            for (int i = 0; i < use[userscounter].taskCount; i++)
            {

                if (use[userscounter].tasks[i].description == tempSearch)
                {
                    cout << "Task " << (i + 1) << ":" << endl
                        << endl;
                    cout << "Description: " << use[userscounter].tasks[i].description << endl;
                    cout << "Priority: " << use[userscounter].tasks[i].priority << endl;
                    cout << "Overdue date is : " << use[userscounter].tasks[i].due_date.day << "/" << use[userscounter].tasks[i].due_date.month << "/" << use[userscounter].tasks[i].due_date.year;
                    found = 1;
                    break;
                }
            }
            if (!found)
                cout << "coundn't find a task with that description, please try again.";
            break;
        case 2:
            cout << "enter priorty level: ";
            cin >> tempPriorty;
            for (int i = 0; i < use[userscounter].taskCount; i++)
            {
                if (use[userscounter].tasks[i].priority == tempPriorty)
                {
                    cout << "Task " << (i + 1) << ":" << endl
                        << endl;
                    cout << "Description: " << use[userscounter].tasks[i].description << endl;
                    cout << "Priority: " << use[userscounter].tasks[i].priority << endl;
                    cout << "Overdue date is : " << use[userscounter].tasks[i].due_date.day << "/" << use[userscounter].tasks[i].due_date.month << "/" << use[userscounter].tasks[i].due_date.year;
                    cout << endl
                        << endl;
                    found = true;
                }
                cout << "=====================\n\n";
            }
            if (found == false)
                cout << "coundn't find a task with that priority, please try again.";
            break;
        case 3:
            // also waiting foe hoss
            cout << "enter task no.";
            cin >> tempNum;
            if (1 <= tempNum || tempNum <= use[userscounter].taskCount)
            {
                cout << "Task " << tempNum << ":" << endl
                    << endl;
                cout << "Description: " << use[userscounter].tasks[tempNum - 1].description << endl;
                cout << "Priority: " << use[userscounter].tasks[tempNum - 1].priority << endl;
                cout << "Overdue date is : " << use[userscounter].tasks[tempNum - 1].due_date.day << "/" << use[userscounter].tasks[tempNum - 1].due_date.month << "/" << use[userscounter].tasks[tempNum - 1].due_date.year;
                cout << endl
                    << endl;
                found = true;
                break;
            }
            cout << "=====================\n\n";

            if (!found)
                cout << "coundn't find a task with that number, please try again.";
            break;
        default:
            break;
        }

        cout << "\n\ndo you want to search again?(y/n): ";
        cin >> con;

    } while (con == 'y' || con == 'Y');
}

void mark_task_as_complete() {     // Mazen ...still editing with (display tasks)
    int n;
    cout << "Completing  task(s)... " << endl;
    while (true)
    {
        cout <<"0 : Cancel"<<endl;
        for (int i = 0; i < use[userscounter].taskCount; i++){
            if(use[userscounter].tasks[i].completed){
                continue;
            }
            cout<< i + 1 << " : " << use[userscounter].tasks[i].description << endl;
        }
        cout << endl << "select number of task to complete(0->" << use[userscounter].taskCount << "):";
        cin >> n;
        if (1 <= n && n <= use[userscounter].taskCount)
            break;
        else if(n==0){
            break;
        }
        else
            cout << "enter valid choice\n";
    }
    if(n!=0){
        n--;
        use[userscounter].tasks[n].completed=true;
    }
    cout<<"Task marked as completed!"<<endl;
}
int edit_task()/*Amin*/
{
     int task_num, ans1; 
    char ans;
    do
    {
        cout<<"0:Cancel"<<endl;
        for(int i=0;i<use[userscounter].taskCount;i++){
            cout<<i+1<<":"<<use[userscounter].tasks[i].description<<endl;
        }
        cout << "which task do you want to edit? Enter task number: ";
        while (true)
        {
            cin >> task_num;
            if(task_num==0){
                break;
            }
            if (task_num >= 1 && task_num <= use[userscounter].taskCount)
                break;
            cout << "\nERROR!!! enter a valid number: ";
        }
        if(task_num==0){
            break;
        }
        cout << "\nwhat do you want to edit in this task?  1->description    2->priority      3->date  ";
        cin >> ans1;
        switch (ans1)
        {
        case 1:
            cout << "\nEnter the new task description: ";
            cin.ignore();
            getline(cin, use[userscounter].tasks[task_num - 1].description);
            break;
        case 2:
            cout << "\nEnter the new priority level(1-5): ";
            while (true)
            {
                cin >> use[userscounter].tasks[task_num - 1].priority;
                if (use[userscounter].tasks[task_num - 1].priority >= 1 && use[userscounter].tasks[task_num - 1].priority <= 5)
                    break;
                cout << "\nERROR!!! invlalid priority level, please enter again: ";
            }
            break;
        case 3:
            cout << "\nPlease enter the new overdue date in (DD-MM-YYYY): ";
            cout << "\nEnter Day (from 1 to 31): ";
            while (true)
            {
                cin >> use[userscounter].tasks[task_num - 1].due_date.day;
                if (use[userscounter].tasks[task_num - 1].due_date.day >= 1 && use[userscounter].tasks[task_num - 1].due_date.day <= 12)
                    break;
                cout << "\nERROR!!! enter a valid day (from 1 to 31): ";
            }
            cout << "Enter month(from 1 to 12): ";
            while (true)
            {
                cin >> use[userscounter].tasks[task_num - 1].due_date.month;
                if (use[userscounter].tasks[task_num - 1].due_date.month >= 1 && use[userscounter].tasks[task_num - 1].due_date.month <= 30)
                    break;
                cout << "\nERROR!!! enter valid month: ";
            }
            cout << "Enter year: ";
            while (true)
            {
                cin >> use[userscounter].tasks[task_num - 1].due_date.year;
                if (use[userscounter].tasks[task_num - 1].due_date.year >= 2024)
                    break;
                cout << "ERROR!!! enter a valid year :) ";
            }
        }
        use[userscounter].tasks[task_num - 1];
        cout << "Do you want to edit again? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return 4;
}

void delete_task()
{
 if (use[userscounter].taskCount == 0)
  {
    cout << " no tasks to delete!\n ";
    return ;
  }
  int n;
  string ans;
  cout << "deleting task(s)... " << endl;
  while (true)
  {
    for(int i=0 ; i < use[userscounter].taskCount ; i++)
      cout << i+1 << " : " << use[userscounter].tasks[i].description << endl;
    cout << endl << "select number of task to delete(1->" << use[userscounter].taskCount << ") (0 to exit):";
    cin >> n;
    if (n == 0)
      return ;
    if (n < 1 || n > use[userscounter].taskCount)
      {
        cout << "enter a valide task!\n";
        continue;
      }
      else
      {
        cout << "are you sure you want to delete task " << n << " ?(yes / no): ";
        cin >> ans;
        if(ans == "no" || ans == "NO")
          continue;
        else if(ans == "yes" || ans == "YES")
          break;
        else
        {
          cout << "enter valide answer!\n";
          continue;
        }
      }
  }
  int i = n - 1;
  for (i; i < use[userscounter].taskCount; i++)
    use[userscounter].tasks[i] = use[userscounter].tasks[i + 1];
  cout << "task deleted successfuly!\n";
  use[userscounter].taskCount--;
}