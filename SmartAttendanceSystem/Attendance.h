#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <string>
using namespace std;

class Attendance {
private:
    int studentId;
    string studentName;
    string date;
    string time;

public:
    Attendance(int id, string name, string d, string t);
    int getId() const;
    string getName() const;
    string getDate() const;
    string getTime() const;
};

#endif
