# Smart-attendance-system[README.md](https://github.com/user-attachments/files/26201433/README.md)
# Smart Attendance System (C++ OOP)

## Overview
A console-based attendance management system built using Object-Oriented Programming in C++.
Designed to demonstrate core OOP principles with a clean, modular structure.

---

## OOP Concepts Used
| Concept | Where Used |
|---|---|
| **Classes & Objects** | `Student`, `Attendance`, `AttendanceSystem` |
| **Encapsulation** | Private data members, public getter methods |
| **Abstraction** | Complex logic hidden inside class methods |
| **Modularity** | Separate `.h` and `.cpp` files per class |

---

## Features
- Add students with ID, Name, and Roll Number
- Mark attendance (auto-captures current date & time)
- View all registered students
- View complete attendance records
- Detect proxy attendance (duplicate entries on same date)
- Input validation for invalid choices

---

## Project Structure
```
SmartAttendanceSystem/
├── main.cpp              → Entry point, menu UI
├── Student.h / .cpp      → Student entity class
├── Attendance.h / .cpp   → Attendance record class
├── AttendanceSystem.h / .cpp → Core logic & operations
└── README.md
```

---

## How to Run

### Compile
```bash
g++ main.cpp Student.cpp Attendance.cpp AttendanceSystem.cpp -o attendance
```

### Execute
```bash
./attendance        # Linux/Mac
attendance.exe      # Windows
```

---

## Sample Output
```
  ================================================
        SMART ATTENDANCE SYSTEM  (C++ OOP)
  ================================================

  Students: 3   |   Records: 0
  ------------------------------------------------
   1. Add Student
   2. Mark Attendance
   3. View All Students
   4. View Attendance Records
   5. Detect Proxy Attendance
   0. Exit
  ------------------------------------------------
```

---

## Author
Vishal Nitin Chaure
Yash Sudhir Shinde
