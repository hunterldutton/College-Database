#ifndef FINAL_PROJECT_HDUTTON_TA_H
#define FINAL_PROJECT_HDUTTON_TA_H

#include "Faculty.h"
#include <string>
using namespace std;

class TA : public Faculty {
private:
    bool isGrader;

public:
    TA();

    explicit TA(string first, string last, string dep, string mail, bool grading);

    bool getGrader();

    void setGrader(bool grader);
};


#endif //FINAL_PROJECT_HDUTTON_TA_H
