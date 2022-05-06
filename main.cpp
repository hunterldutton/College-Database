#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory>
#include "unistd.h"
#include "Professor.h"
#include "Administrator.h"
#include "TA.h"

using namespace std;

#ifdef _WIN32
const string python = "py ";
#else
const string python = "python ";
#endif

/**
 * Initialize unique pointer vectors to push
 * Faculty objects to (Professors, Administrators, TAs)
 */
vector<unique_ptr<Professor>> profVector;
vector<unique_ptr<Administrator>> adminVector;
vector<unique_ptr<TA>> TAVector;

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
 *  Calls a menu to display the different types of
 *  "show" commands available
 */
void showMembers();

/**
 * showAllMembers():
 * Calls Python file to print all members from all
 * three tables in the database
 */
void showAllMembers();

/**
 * showProf():
 * Calls Python file to print all members
 * from the Professor table
 */
void showProf();

/**
 * showAdmin():
 * Calls Python file to print all members
 * from the Administrator table
 */
void showAdmin();

/**
 * showTA():
 * Calls Python file to print all members
 * from the TA table
 */
void showTA();

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
 * Print menu for adding Professors,
 * Administrators, and TAs
 */
void addMember();

/**
 * addProf():
 * Add a Professor to the database
 */
void addProf();

/**
 * addAdmin():
 * Add a Administrator to the database
 */
void addAdmin();

/**
 * addTA():
 * Add a TA to the database
 */
void addTA();

/**
 * removeMember():
 * Take in input, checks against local vector to find what faculty type
 * the member is, executes system command to call python file,
 * pass "removeMember" argument and string representing faculty type,
 * and input firstName and lastName strings as arguments.
 */
void removeMember();

/**
 * updateVectorsPy():
 * Calls Python file with "updateVectors" to update .txt files
 * with current information from the Database
 */
void updateVectorsPy();

/**
 * updateVectors():
 * Takes information from .txt files, creates unique pointer vectors
 * of each Object (Professor, Administrator, TA) to use locally
 */
void updateVectors();

// Run the menu function
int main(){
    updateVectorsPy();
    updateVectors();
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
    cout << "Select which you want to view:" << endl;
    cout << "1. All Faculty" << endl;
    cout << "2. Professors" << endl;
    cout << "3. Administrators" << endl;
    cout << "4. TAs" << endl;
    cout << "5. Go back" << endl;
    cout << "Make your selection: ";
    int choice = validMenuBounds(1, 5);
    if (choice == 1){
        showAllMembers();
    }
    else if (choice == 2){
        showProf();
    }
    else if (choice == 3){
        showAdmin();
    }
    else if (choice == 4){
        showTA();
    }
    else {
        printMenu();
    }
}

void showAllMembers(){
    cout << endl;
    string command = python + "../sqlConnect.py printMembers";
    system(command.c_str());
    printMenu();
}

void showProf(){
    cout << endl;
    string command = python + "../sqlConnect.py printProfessors";
    system(command.c_str());
    printMenu();
}

void showAdmin(){
    cout << endl;
    string command = python + "../sqlConnect.py printAdmin";
    system(command.c_str());
    printMenu();
}

void showTA(){
    cout << endl;
    string command = python + "../sqlConnect.py printTA";
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
    cout << endl << "Please select which type of member you want to add:" << endl;
    cout << "1. Professor" << endl;
    cout << "2. Admin" << endl;
    cout << "3. TA" << endl;
    cout << "4. Go back" << endl;
    cout << "Make your selection: ";
    int choice = validMenuBounds(1, 4);
    if (choice == 1) {
        addProf();
    }
    else if (choice == 2){
        addAdmin();
    }
    else if (choice == 3){
        addTA();
    }
    else {
        printMenu();
    }
}

void addProf(){
    string endline, firstName, lastName, department, email, officeBuild;
    int officeNum, intToValidate;
    cout << "Enter the first name of the professor you want to add: ";
    getline(cin, endline);
    firstName = stringInput();
    cout << "Enter the last name of the professor you want to add: ";
    lastName = stringInput();
    cout << "Enter the department of the professor you want to add: ";
    department = stringInput();
    replace(department.begin(), department.end(), ' ', '-');
    cout << "Enter the email of the professor you want to add: ";
    email = stringInput();
    cout << "Enter the office building of the professor you want to add: ";
    officeBuild = stringInput();
    cout << "Enter the office room number of the professor you want to add: ";
    while(!(cin >> intToValidate)){
        cout << "Please enter a valid number: ";
        cin.clear();
        string endline;
        getline(cin, endline);
    }
    officeNum = intToValidate;
    string command = python + "../sqlConnect.py addMember " + firstName + " " + lastName
                     + " " + department + " " + email + " " + officeBuild + " " + to_string(officeNum) + " professors";
    profVector.push_back(make_unique<Professor>(firstName, lastName, department, email, officeBuild, officeNum));
    system(command.c_str());
    cout << endl << firstName << " " << lastName << " " << "was added to the list of Professors." << endl << endl;
    updateVectorsPy();
    updateVectors();
    printMenu();
}

void addAdmin(){
    string endline, firstName, lastName, department, email, officeBuild;
    int officeNum, intToValidate;
    cout << "Enter the first name of the administrator you want to add: ";
    getline(cin, endline);
    firstName = stringInput();
    cout << "Enter the last name of the administrator you want to add: ";
    lastName = stringInput();
    cout << "Enter the department of the administrator you want to add: ";
    department = stringInput();
    replace(department.begin(), department.end(), ' ', '-');
    cout << "Enter the email of the administrator you want to add: ";
    email = stringInput();
    cout << "Enter the office building of the administrator you want to add: ";
    officeBuild = stringInput();
    cout << "Enter the office room number of the administrator you want to add: ";
    while(!(cin >> intToValidate)){
        cout << "Please enter a valid number: ";
        cin.clear();
        string endline;
        getline(cin, endline);
    }
    officeNum = intToValidate;
    string command = python + "../sqlConnect.py addMember " + firstName + " " + lastName
                     + " " + department + " " + email + " " + officeBuild + " " + to_string(officeNum) + " admin";
    adminVector.push_back(make_unique<Administrator>(firstName, lastName, department, email, officeBuild, officeNum));
    system(command.c_str());
    cout << endl << firstName << " " << lastName << " " << "was added to the list of Administrators." << endl << endl;
    updateVectorsPy();
    updateVectors();
    printMenu();
}

void addTA(){
    string endline, firstName, lastName, department, email;
    char graderAnswer;
    bool grader;
    cout << "Enter the first name of the TA you want to add: ";
    getline(cin, endline);
    firstName = stringInput();
    cout << "Enter the last name of the TA you want to add: ";
    lastName = stringInput();
    cout << "Enter the department of the TA you want to add: ";
    department = stringInput();
    replace(department.begin(), department.end(), ' ', '-');
    cout << "Enter the email of the TA you want to add: ";
    email = stringInput();
    cout << "Is the TA a grader? (Y/N): ";
    cin >> graderAnswer;
    toupper(graderAnswer);
    while (graderAnswer != 'Y' && graderAnswer != 'N'){
        cout << "Invalid answer. Please try again." << endl;
        cout << "Is the TA a grader? (Y/N)";
        cin >> graderAnswer;
        toupper(graderAnswer);
    }
    if (graderAnswer == 'Y'){
        grader = true;
    }
    else {
        grader = false;
    }
    string command = python + "../sqlConnect.py addMember " + firstName + " " + lastName
                     + " " + department + " " + email + " " + to_string(int(grader)) +" TA";
    TAVector.push_back(make_unique<TA>(firstName, lastName, department, email, grader));
    system(command.c_str());
    cout << endl << firstName << " " << lastName << " " << "was added to the list of TAs." << endl << endl;
    updateVectorsPy();
    updateVectors();
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
    for (unique_ptr<Professor> &prof : profVector){
        if (prof->getFirstName() == firstName && prof->getLastName() == lastName){
            command += " professors";
            system(command.c_str());
        }
    }
    for (unique_ptr<Administrator> &admin : adminVector){
        if (admin->getFirstName() == firstName && admin->getLastName() == lastName){
            command += " admin";
            system(command.c_str());
        }
    }
    for (unique_ptr<TA> &ta : TAVector){
        if (ta->getFirstName() == firstName && ta->getLastName() == lastName){
            command += " TA";
            system(command.c_str());
        }
    }
    updateVectorsPy();
    updateVectors();
    printMenu();
}

void updateVectorsPy(){
    string command = python + "../sqlConnect.py updateVectors";
    system(command.c_str());
}

void updateVectors(){
    profVector.clear();
    adminVector.clear();
    TAVector.clear();
    string profInput;
    ifstream prof("../professorList.txt");
    if (prof.is_open()){
        while (getline(prof, profInput)){
            size_t stringStart;
            size_t stringEnd = 0;
            vector<string> profInputSplit;
            while ((stringStart = profInput.find_first_not_of(' ', stringEnd)) != string::npos){
                stringEnd = profInput.find(' ', stringStart);
                profInputSplit.push_back(profInput.substr(stringStart, stringEnd-stringStart));
            }
            profVector.push_back(make_unique<Professor>(profInputSplit[0], profInputSplit[1], profInputSplit[2], profInputSplit[3],
                                 profInputSplit[4], stoi(profInputSplit[5])));
        }
    }
    prof.close();
    string adminInput;
    ifstream admin("../adminList.txt");
    if (admin.is_open()){
        while (getline(admin, adminInput)){
            size_t stringStart;
            size_t stringEnd = 0;
            vector<string> adminInputSplit;
            while ((stringStart = adminInput.find_first_not_of(' ', stringEnd)) != string::npos){
                stringEnd = adminInput.find(' ', stringStart);
                adminInputSplit.push_back(adminInput.substr(stringStart, stringEnd-stringStart));
            }
            adminVector.push_back(make_unique<Administrator>(adminInputSplit[0], adminInputSplit[1], adminInputSplit[2], adminInputSplit[3],
                                                        adminInputSplit[4], stoi(adminInputSplit[5])));
        }
    }
    admin.close();
    string TAInput;
    ifstream TAFile("../TAList.txt");
    if (TAFile.is_open()){
        while (getline(TAFile, TAInput)){
            size_t stringStart;
            size_t stringEnd = 0;
            vector<string> TAInputSplit;
            while ((stringStart = TAInput.find_first_not_of(' ', stringEnd)) != string::npos){
                stringEnd = TAInput.find(' ', stringStart);
                TAInputSplit.push_back(TAInput.substr(stringStart, stringEnd-stringStart));
            }
            bool grader;
            if (stoi(TAInputSplit[4]) == 1){
                grader = true;
            }
            else{
                grader = false;
            }
            TAVector.push_back(make_unique<TA>(TAInputSplit[0], TAInputSplit[1], TAInputSplit[2], TAInputSplit[3], grader));
        }
    }
    TAFile.close();
}