#include "Professor.h"
using namespace std;

Professor::Professor() : Faculty(), officeBuild(""), officeNum(0){
    setFacultyType(professor);
};

Professor::Professor(string first, string last, string dep, string mail, string build, int num) :
    Faculty(first, last, dep, mail, professor), officeBuild(build), officeNum(num){};

string Professor::getOfficeBuild(){
    return officeBuild;
}

int Professor::getOfficeNum(){
    return officeNum;
}

void Professor::setOfficeBuild(string build){
    officeBuild = build;
}

void Professor::setOfficeNum(int num){
    officeNum = num;
}
