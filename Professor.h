#ifndef FINAL_PROJECT_HDUTTON_PROFESSOR_H
#define FINAL_PROJECT_HDUTTON_PROFESSOR_H

#include "Faculty.h"
#include <string>
using namespace std;

class Professor : public Faculty {
private:
    string officeBuild;
    int officeNum;

public:
    Professor();

    explicit Professor(string first, string last, string dep, string mail, string build, int num);

    string getOfficeBuild();
    int getOfficeNum();

    void setOfficeBuild(string build);
    void setOfficeNum(int num);
};

#endif //FINAL_PROJECT_HDUTTON_PROFESSOR_H
