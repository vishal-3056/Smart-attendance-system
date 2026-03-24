#include "Attendance.h"

Attendance::Attendance(int id, string name, string d, string t) {
    studentId = id;
    studentName = name;
    date = d;
    time = t;
}

int Attendance::getId() const {
    return studentId;
}

string Attendance::getName() const {
    return studentName;
}

string Attendance::getDate() const {
    return date;
}

string Attendance::getTime() const {
    return time;
}
