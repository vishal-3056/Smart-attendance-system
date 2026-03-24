#include "Student.h"

Student::Student(int i, string n, string r) {
    id = i;
    name = n;
    rollNo = r;
}

int Student::getId() const {
    return id;
}

string Student::getName() const {
    return name;
}

string Student::getRollNo() const {
    return rollNo;
}
