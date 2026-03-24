#ifndef ATTENDANCESYSTEM_H
#define ATTENDANCESYSTEM_H

#include <vector>
#include <string>
#include "Student.h"
#include "Attendance.h"

using namespace std;

class AttendanceSystem {
private:
    vector<Student> students;
    vector<Attendance> records;

    // Helper: get current date and time as strings
    string getCurrentDate() const;
    string getCurrentTime() const;

    // Helper: find student by ID, returns -1 if not found
    int findStudentIndex(int id) const;

public:
    void addStudent(int id, string name, string rollNo);
    void markAttendance(int id);
    void showAttendance() const;
    void showStudents() const;
    void detectProxy() const;
    int getTotalStudents() const;
    int getTotalRecords() const;
};

#endif
