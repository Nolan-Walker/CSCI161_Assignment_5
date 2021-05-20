//
//  main.cpp
//  assignment 5
//
//
//
//
//


#include "dictionary.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    //create dictionary list
    Dictionary list;
    //try to open a file if it exists
    list.loadData();

    char userCommand = NULL;
    
    //introduction
    cout << "*** Welcome to Homework tracker ***" << endl << endl;
    cout << "Enter L to list all homework names" << endl;
    cout << "or S to show the information of homework by name " << endl;
    cout << "or R to remove a completed homework assignment" << endl;
    cout << "or A to add a new homework assigment" << endl;
    cout << "or U to update the submission deadline of an assignment" << endl << endl;
    cout << "or H for help (displays this menu)" << endl;
    cout << "or E to export to homework.txt and exit program" << endl;
    
    //loop with conditions dependent on user command
    while (userCommand != 'e' || userCommand != 'E') {
        
        cout << "------------------------------" << endl;
        cout << "Please enter your choice: ";
        cin >> userCommand;
        cout << "------------------------------";
        cout << endl << endl;
        
        //show list of homework names
        if (userCommand == 'l' || userCommand == 'L') {
            list.printNames();
            
        } else if (userCommand == 's' || userCommand == 'S') {
            //show details of homework by name
            string homeworkName;
            cout << "Please enter the name of the assignment you" << endl;
            cout << "would like to see the details of" << endl;
            getline(cin, homeworkName);
            Data *ptr = new Data;
            ptr = &list.lookup(homeworkName);
            cout << "Here is the info on: ";
            cout << ptr -> homework_name << endl;
            cout << ptr -> submit_deadline << endl;
            cout << ptr -> teacher_info << endl;
            cout << ptr -> description << endl;
            
            //help: display option menu
        } else if (userCommand == 'h' || userCommand == 'H') {
            cout << "Enter L to list all homework names" << endl;
            cout << "or S to show the information of homework by name " << endl;
            cout << "or R to remove a completed homework assignment" << endl;
            cout << "or A to add a new homework assigment" << endl;
            cout << "or U to update the submission deadline of an assignment" << endl << endl;
            cout << "or H for help (displays this menu)" << endl;
            cout << "or E to export to homework.txt and exit program" << endl;
            
            //remove homework assignment from list by name
        } else if (userCommand == 'r' || userCommand == 'R') {
            string homeworkName;
            cout << "Please enter the name of the assignment you'd like to remove from the list." << endl;
            getline(cin, homeworkName);
            list.remove(homeworkName);
            cout << "It has been removed" << endl;
            
        } else if (userCommand == 'a' || userCommand == 'A') {
            string homeworkName;
            cout << "Please enter the name of the assignment you'd like to add to the list." << endl;
            getline(cin, homeworkName);
            Data *ptr = new Data;
            ptr -> homework_name = homeworkName;
            cout << "Please enter the submission deadline." << endl;
            getline(cin, ptr->submit_deadline);
            cout << "Please enter teacher info." << endl;
            getline(cin, ptr->teacher_info);
            cout << "Please enter description of assignment" << endl;
            getline(cin, ptr->description);
        
        } else if (userCommand == 'u' || userCommand == 'U') {
            string homeworkName;
            cout << "Please enter the name of the assignment you would like to update the submission deadline of" << endl;
            getline(cin, homeworkName);
            Data *ptr = &list.lookup(homeworkName);
            cout << "Please enter the new submission deadline" << endl;
            getline(cin, ptr -> submit_deadline);
            cout << "The new submission deadline is as follows: " << ptr->submit_deadline << endl;
        
        } else if (userCommand == 'e' || userCommand == 'E') {
            //NO TIME! :(
        }

        
    }

    return 0;
}
