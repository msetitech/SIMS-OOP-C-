#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Student class to store student information
class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    // Constructor to initialize student data
    Student(string name, int rollNumber, float marks) {
        this->name = name;
        this->rollNumber = rollNumber;
        this->marks = marks;
    }

    // Getters for student data
    string getName() const {
        return name;
    }

    int getRollNumber() const {
        return rollNumber;
    }

    float getMarks() const {
        return marks;
    }

    // Display student information
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

// StudentManagementSystem class to manage the student collection
class StudentManagementSystem {
private:
    vector<Student> students;

public:
    // Add a student to the system
    void addStudent(const string &name, int rollNumber, float marks) {
        Student student(name, rollNumber, marks);
        students.push_back(student);
        cout << "Student added successfully!" << endl;
    }

    // Display all students
    void displayAllStudents() const {
        if (students.empty()) {
            cout << "No students found!" << endl;
            return;
        }

        for (const auto &student : students) {
            student.display();
            cout << "-----------------------------" << endl;
        }
    }

    // Search a student by roll number
    void searchStudent(int rollNumber) const {
        bool found = false;
        for (const auto &student : students) {
            if (student.getRollNumber() == rollNumber) {
                student.display();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student with roll number " << rollNumber << " not found!" << endl;
        }
    }

    // Remove a student by roll number
    void removeStudent(int rollNumber) {
        auto it = students.begin();
        while (it != students.end()) {
            if (it->getRollNumber() == rollNumber) {
                it = students.erase(it); // Remove the student
                cout << "Student removed successfully!" << endl;
                return;
            } else {
                ++it;
            }
        }
        cout << "Student with roll number " << rollNumber << " not found!" << endl;
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        // Display menu
        cout << "Student Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student by Roll Number" << endl;
        cout << "4. Remove Student by Roll Number" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        string name;
        int rollNumber;
        float marks;

        switch (choice) {
            case 1:
                // Add student
                cout << "Enter name: ";
                cin.ignore();  // Ignore leftover newline character from previous input
                getline(cin, name);
                cout << "Enter roll number: ";
                cin >> rollNumber;
                cout << "Enter marks: ";
                cin >> marks;
                sms.addStudent(name, rollNumber, marks);
                break;
            case 2:
                // Display all students
                sms.displayAllStudents();
                break;
            case 3:
                // Search student by roll number
                cout << "Enter roll number to search: ";
                cin >> rollNumber;
                sms.searchStudent(rollNumber);
                break;
            case 4:
                // Remove student by roll number
                cout << "Enter roll number to remove: ";
                cin >> rollNumber;
                sms.removeStudent(rollNumber);
                break;
            case 5:
                cout << "Exiting system..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
