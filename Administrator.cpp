#include "Administrator.h"
using namespace std;

Administrator::Administrator() : Faculty(), officeBuild(""), officeNum(0){
    setFacultyType(admin);
};

Administrator::Administrator(string first, string last, string dep, string mail, string build, int num) :
        Faculty(first, last, dep, mail, admin), officeBuild(build){};

string Administrator::getOfficeBuild(){
    return officeBuild;
}

int Administrator::getOfficeNum(){
    return officeNum;
}

void Administrator::setOfficeBuild(string build){
    officeBuild = build;
}

void Administrator::setOfficeNum(int num){
    officeNum = num;
}
