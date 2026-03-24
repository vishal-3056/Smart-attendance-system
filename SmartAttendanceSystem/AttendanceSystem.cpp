#include <iostream>
#include <iomanip>
#include <ctime>
#include "AttendanceSystem.h"

using namespace std;

// ── Helper: get today's date as DD/MM/YYYY ──────────────────────────────────
string AttendanceSystem::getCurrentDate() const {
    time_t now = time(0);
    tm* t = localtime(&now);
    char buf[11];
    strftime(buf, sizeof(buf), "%d/%m/%Y", t);
    return string(buf);
}

// ── Helper: get current time as HH:MM ───────────────────────────────────────
string AttendanceSystem::getCurrentTime() const {
    time_t now = time(0);
    tm* t = localtime(&now);
    char buf[6];
    strftime(buf, sizeof(buf), "%H:%M", t);
    return string(buf);
}

// ── Helper: find student index by ID ────────────────────────────────────────
int AttendanceSystem::findStudentIndex(int id) const {
    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].getId() == id)
            return i;
    }
    return -1;
}

// ── Add a new student ────────────────────────────────────────────────────────
void AttendanceSystem::addStudent(int id, string name, string rollNo) {
    if (findStudentIndex(id) != -1) {
        cout << "  [!] Student with ID " << id << " already exists.\n";
        return;
    }
    students.push_back(Student(id, name, rollNo));
    cout << "  [+] Student '" << name << "' (Roll: " << rollNo << ") added successfully.\n";
}

// ── Mark attendance for a student ───────────────────────────────────────────
void AttendanceSystem::markAttendance(int id) {
    int idx = findStudentIndex(id);
    if (idx == -1) {
        cout << "  [!] No student found with ID " << id << ". Please add student first.\n";
        return;
    }

    string today = getCurrentDate();

    // Check if already marked today (proxy guard)
    for (auto& r : records) {
        if (r.getId() == id && r.getDate() == today) {
            cout << "  [!] Attendance already marked for '" << students[idx].getName()
                 << "' today (" << today << "). Possible PROXY detected!\n";
            return;
        }
    }

    string now = getCurrentTime();
    records.push_back(Attendance(id, students[idx].getName(), today, now));
    cout << "  [+] Attendance marked for '" << students[idx].getName()
         << "' at " << now << " on " << today << ".\n";
}

// ── Show all registered students ────────────────────────────────────────────
void AttendanceSystem::showStudents() const {
    if (students.empty()) {
        cout << "  [!] No students registered yet.\n";
        return;
    }
    cout << "\n  " << left << setw(6) << "ID"
         << setw(20) << "Name"
         << setw(12) << "Roll No" << "\n";
    cout << "  " << string(38, '-') << "\n";
    for (auto& s : students) {
        cout << "  " << left << setw(6) << s.getId()
             << setw(20) << s.getName()
             << setw(12) << s.getRollNo() << "\n";
    }
}

// ── Show all attendance records ──────────────────────────────────────────────
void AttendanceSystem::showAttendance() const {
    if (records.empty()) {
        cout << "  [!] No attendance records found.\n";
        return;
    }
    cout << "\n  " << left << setw(6) << "ID"
         << setw(20) << "Name"
         << setw(14) << "Date"
         << setw(8)  << "Time" << "\n";
    cout << "  " << string(48, '-') << "\n";
    for (auto& r : records) {
        cout << "  " << left << setw(6) << r.getId()
             << setw(20) << r.getName()
             << setw(14) << r.getDate()
             << setw(8)  << r.getTime() << "\n";
    }
}

// ── Detect proxy attendance ──────────────────────────────────────────────────
void AttendanceSystem::detectProxy() const {
    if (records.size() < 2) {
        cout << "  [!] Not enough records to detect proxy.\n";
        return;
    }

    bool found = false;
    for (int i = 0; i < (int)records.size(); i++) {
        for (int j = i + 1; j < (int)records.size(); j++) {
            if (records[i].getId() == records[j].getId() &&
                records[i].getDate() == records[j].getDate()) {
                cout << "  [WARNING] Duplicate entry detected for ID: "
                     << records[i].getId()
                     << " (" << records[i].getName() << ")"
                     << " on " << records[i].getDate() << "!\n";
                found = true;
            }
        }
    }
    if (!found)
        cout << "  [OK] No proxy attendance detected.\n";
}

int AttendanceSystem::getTotalStudents() const {
    return (int)students.size();
}

int AttendanceSystem::getTotalRecords() const {
    return (int)records.size();
}
