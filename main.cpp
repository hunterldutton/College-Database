#include <iostream>
#include <string>
#include <algorithm>
#include "unistd.h"
#include "Faculty.h"

using namespace std;

#ifdef _WIN32
const string python = "py ";
#else
const string python = "python ";
#endif

/**
 * printMenu():
 * Print out menu options, take in menu option,
 * call function corresponding to input
 */
void printMenu();

/**
 * validMenuBounds(int lowerBound, int upperBound):
 * Take in lower and upper bounds, make sure user input is
 * an integer between those two, return the choice
 */
int validMenuBounds(int lowerBound, int upperBound);

/**
 * stringInput():
 * Get a user-input string, make sure it comes in and
 * isn't blank, return it
 */
string stringInput();

/**
 * showMembers():
 *  Execute system command to call python file,
 *  pass "printMembers" argument
 */
void showMembers();

/**
 * searchMembers():
 * Print out search options, take in menu option,
 * call search function corresponding to input
 *
 */
void searchMembers();

/**
 * searchByDep():
 * Take in input, execute system command to call python file,
 * pass "searchDep" argument, and input department string
 * as an argument
 */
void searchByDep();

/**
 * searchByName():
 * Take in input, execute system command to call python file,
 * pass "searchName" argument, and input firstName
 * and lastName strings as arguments
 */
void searchByName();

/**
 * addMember():
 * Take in input, execute system command to call python file,
 * pass "addMember" argument, and input firstName, lastName,
 * department, email, and office building strings as arguments,
 * as well as the office room number as an integer argument
 */
void addMember();

/**
 * removeMember():
 * Take in input, execute system command to call python file,
 * pass "removeMember" argument, and input firstName and lastName
 * strings as arguments.
 */
void removeMember();

// Run the menu function
int main(){
    printMenu();
    return 0;
}

void printMenu(){
    cout << "Welcome to the Faculty Member Database!" << endl;
    cout << "1. Show faculty members" << endl;
    cout << "2. Search for faculty members" << endl;
    cout << "3. Add faculty members" << endl;
    cout << "4. Remove faculty members" << endl;
    cout << "5. Quit" << endl;
    cout << "Make your selection: ";
    int choice = validMenuBounds(1, 5);
    if (choice == 1){
        showMembers();
    }
    else if (choice == 2){
        searchMembers();
    }
    else if (choice == 3){
        addMember();
    }
    else if (choice == 4){
        removeMember();
    }
    else {
        cout << endl << "Thank you for using the Faculty List Editor." << endl;
        sleep(2);
    }
}

int validMenuBounds(int lowerBound, int upperBound) {
    int menuChoice = 0;
    bool valid = false;
    while (!valid) {
        while (!(cin >> menuChoice)) {
            cout << "Please make a valid selection: ";
            cin.clear();
            string endline;
            getline(cin, endline);
        }
        if (menuChoice <= (lowerBound-1) || menuChoice >= (upperBound+1)) {
            cout << "Please make a valid selection: " << endl;
        }
        else {
            valid = true;
        }
    }
    return menuChoice;
}

string stringInput(){
    string returnString, endline;
    getline(cin, returnString);
    while (!cin || returnString.empty()){
        cout << "Please enter a valid response: ";
        cin.clear();
        getline(cin, returnString);
    }
    return returnString;
}

void showMembers(){
    cout << endl;
    string command = python + "../sqlConnect.py printMembers";
    system(command.c_str());
    printMenu();
}

void searchMembers(){
    cout << endl << "Search for faculty members:" << endl;
    cout << "1. Search by Department" << endl;
    cout << "2. Search by Name" << endl;
    cout << "3. Go back" << endl;
    cout << "Make your selection: ";
    int choice = validMenuBounds(1, 3);
    if (choice == 1){
        searchByDep();
    }
    else if (choice == 2){
        searchByName();
    }
    else {
        printMenu();
    }
}

void searchByDep(){
    string endline;
    cout << "Enter the department you want to search for: ";
    getline(cin, endline);
    string department = stringInput();
    replace(department.begin(), department.end(), ' ', '-');
    cout << endl;
    string command = python + "../sqlConnect.py searchDep " + department;
    system(command.c_str());
    printMenu();
}

void searchByName(){
    string endline;
    cout << "Enter the first name of who you want to search for: ";
    getline(cin, endline);
    string firstName = stringInput();
    cout << "Enter the last name of who you want to search for: ";
    string lastName = stringInput();
    cout << endl;
    string command = python + "../sqlConnect.py searchName " + firstName + " " + lastName;
    system(command.c_str());
    cout << endl;
    printMenu();
}

void addMember() {
    string endline, firstName, lastName, department, email, officeBuild;
    int officeNum, intToValidate;
    cout << "Enter the first name of who you want to add: ";
    getline(cin, endline);
    firstName = stringInput();
    cout << "Enter the last name of who you want to add: ";
    lastName = stringInput();
    cout << "Enter the department of who you want to add: ";
    department = stringInput();
    replace(department.begin(), department.end(), ' ', '-');
    cout << "Enter the email of who you want to add: ";
    email = stringInput();
    cout << "Enter the office building of who you want to add: ";
    officeBuild = stringInput();
    cout << "Enter the office room number of who you want to add: ";
    while(!(cin >> intToValidate)){
        cout << "Please enter a valid number: ";
        cin.clear();
        string endline;
        getline(cin, endline);
    }
    officeNum = intToValidate;
    string command = python + "../sqlConnect.py addMember " + firstName + " " + lastName
            + " " + department + " " + email + " " + officeBuild + " " + to_string(officeNum);
    system(command.c_str());
    cout << endl << firstName << " " << lastName << " " << "was added to the faculty." << endl << endl;
    printMenu();
}

void removeMember(){
    string endline, firstName, lastName;
    cout << "Enter the first name of who you want to remove: ";
    getline(cin, endline);
    firstName = stringInput();
    cout << "Enter the last name of who you want to remove: ";
    lastName = stringInput();
    string command = python + "../sqlConnect.py removeMember " + firstName + " " + lastName;
    system(command.c_str());
    printMenu();
}