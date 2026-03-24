#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    string rollNo;

public:
    Student(int i, string n, string r);
    int getId() const;
    string getName() const;
    string getRollNo() const;
};

#endif
