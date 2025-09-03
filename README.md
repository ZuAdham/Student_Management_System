# Student Management System 🎓

A simple console-based application in C that allows users to manage student records.  
It provides options to add, search, update, and delete student information, along with GPA statistics.

## Features
- Add Student – Register a new student with ID, name, and GPA.  
- Display Students – Show all stored student records.  
- Search Student by ID – Quickly find a student using their unique ID.  
- Update Student – Modify existing student details.  
- Calculate Average GPA – Get the average GPA of all students.  
- Highest GPA – Find the top-performing student.  
- Delete Student – Remove a student record.  
- Exit – Close the program safely.  

## Example Menu
-----------------------------------------------------
    Welcome To Student Management System
-----------------------------------------------------
1. Add Student
2. Display Students
3. Search for a Student by ID
4. Update Student Information
5. Calculate Average GPA
6. Student with Highest GPA
7. Delete Student
8. Exit
-----------------------------------------------------
Enter Choice :

## How to Run
1. Clone the repository:
   git clone https://github.com/ZuAdham/Student_Management_System.git
2. Compile the code:
   gcc student_management.c -o sms
3. Run the program:
   ./sms

## Project Structure
Student_Management_System/
├─ student_management.c   # Main source code
├─ README.md              # Project description
└─ .gitignore             # Ignored files

## Author
ZuAdham – Embedded Systems & IoT Enthusiast

-----------------------------------------------------
.gitignore
-----------------------------------------------------

# Compiled source
*.exe
*.o
*.out

# Debug / build files
*.dSYM/
*.obj
*.dll
*.so
*.a
*.lib

# Logs / temp
*.log
*.tmp
*.bak

# IDE / Editor files
.vscode/
.idea/
*.swp
