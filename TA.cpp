#include "TA.h"
using namespace std;

TA::TA() : Faculty(), isGrader(false){
    setFacultyType(teachAssist);
};

TA::TA(string first, string last, string dep, string mail, bool grading) :
        Faculty(first, last, dep, mail, teachAssist), isGrader(grading){};

bool TA::getGrader(){
    return isGrader;
}

void TA::setGrader(bool grader){
    isGrader = grader;
}

