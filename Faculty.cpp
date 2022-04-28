#include "Faculty.h"
using namespace std;

Faculty::Faculty() : firstName(""), lastName(""), department(""), email(""){}

Faculty::Faculty(string first, string last, string dep, string mail, type fac) : firstName(first), lastName(last), department(dep), email(mail), facultyType(fac){}

string Faculty::getFirstName(){
    return firstName;
}

string Faculty::getLastName(){
    return lastName;
}

string Faculty::getDepartment(){
    return department;
}

string Faculty::getEmail(){
    return email;
}

Faculty::type Faculty::getFacultyType() {
    return facultyType;
}

void Faculty::setFirstName(string fn){
    firstName = fn;
}

void Faculty::setLastName(string ln){
    lastName = ln;
}

void Faculty::setDeparment(string dep){
    department = dep;
}

void Faculty::setEmail(string em){
    email = em;
}

void Faculty::setFacultyType(Faculty::type fac) {
    facultyType = fac;
}


