#include <iostream>
#include <string>
#include <limits>
#include "AttendanceSystem.h"

using namespace std;

void printHeader() {
    cout << "\n";
    cout << "  ================================================\n";
    cout << "        SMART ATTENDANCE SYSTEM  (C++ OOP)        \n";
    cout << "  ================================================\n";
}

void printMenu(int totalStudents, int totalRecords) {
    cout << "\n";
    cout << "  Students: " << totalStudents << "   |   Records: " << totalRecords << "\n";
    cout << "  ------------------------------------------------\n";
    cout << "   1. Add Student\n";
    cout << "   2. Mark Attendance\n";
    cout << "   3. View All Students\n";
    cout << "   4. View Attendance Records\n";
    cout << "   5. Detect Proxy Attendance\n";
    cout << "   0. Exit\n";
    cout << "  ------------------------------------------------\n";
    cout << "  Enter choice: ";
}

int main() {
    AttendanceSystem system;
    int choice;

    printHeader();

    // Pre-load a couple of demo students so it's easy to demo in viva
    system.addStudent(101, "Rahul Sharma", "CS-01");
    system.addStudent(102, "Priya Patil", "CS-02");
    system.addStudent(103, "Vishal Chaure", "CS-03");
    cout << "\n  [Demo data loaded - 3 students added]\n";

    do {
        printMenu(system.getTotalStudents(), system.getTotalRecords());
        cin >> choice;

        // Input validation
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  [!] Invalid input. Please enter a number.\n";
            continue;
        }

        cout << "\n";

        switch (choice) {
            case 1: {
                int id;
                string name, rollNo;
                cout << "  Enter Student ID   : ";
                cin >> id;
                cout << "  Enter Student Name : ";
                cin.ignore();
                getline(cin, name);
                cout << "  Enter Roll Number  : ";
                cin >> rollNo;
                system.addStudent(id, name, rollNo);
                break;
            }

            case 2: {
                int id;
                cout << "  Enter Student ID to mark attendance: ";
                cin >> id;
                system.markAttendance(id);
                break;
            }

            case 3:
                system.showStudents();
                break;

            case 4:
                system.showAttendance();
                break;

            case 5:
                system.detectProxy();
                break;

            case 0:
                cout << "  Exiting... Thank you!\n\n";
                break;

            default:
                cout << "  [!] Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
