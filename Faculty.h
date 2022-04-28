#ifndef FINAL_PROJECT_HDUTTON_FACULTY_H
#define FINAL_PROJECT_HDUTTON_FACULTY_H

#include <string>
using namespace std;

class Faculty {

private:
    string firstName, lastName, department, email;

public:
    enum type{professor, admin, teachAssist};
    type facultyType;

    Faculty();

    explicit Faculty(string first, string last, string dep, string mail, type fac);

    // Getters
    string getFirstName();
    string getLastName();
    string getDepartment();
    string getEmail();
    type getFacultyType();

    void setFirstName(string fn);
    void setLastName(string ln);
    void setDeparment(string dep);
    void setEmail(string em);
    void setFacultyType(type fac);
};

#endif //FINAL_PROJECT_HDUTTON_FACULTY_H
