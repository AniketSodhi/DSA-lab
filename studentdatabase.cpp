#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

// Function to add student information to the file
void addStudent() {
    ofstream outFile("student_data.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    Student newStudent;
    cout << "Enter Roll Number: ";
    cin >> newStudent.rollNumber;
    cout << "Enter Name: ";
    cin.ignore(); // Ignore the newline character left in the stream
    getline(cin, newStudent.name);
    cout << "Enter Division: ";
    getline(cin, newStudent.division);
    cout << "Enter Address: ";
    getline(cin, newStudent.address);

    outFile << newStudent.rollNumber << "," << newStudent.name << "," << newStudent.division << "," << newStudent.address << endl;

    cout << "Student information added successfully." << endl;

    outFile.close();
}

// Function to delete student information from the file
void deleteStudent(int rollNumberToDelete) {
    ifstream inFile("student_data.txt");
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cerr << "Error creating temporary file." << endl;
        return;
    }

    bool found = false;
    Student student;
    while (inFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber != rollNumberToDelete) {
            tempFile << student.rollNumber << "," << student.name << "," << student.division << "," << student.address << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    if (found) {
        remove("student_data.txt");
        rename("temp.txt", "student_data.txt");
        cout << "Student information deleted successfully." << endl;
    } else {
        remove("temp.txt");
        cout << "Student with Roll Number " << rollNumberToDelete << " not found." << endl;
    }
}

// Function to display information of a particular student
void displayStudent(int rollNumberToDisplay) {
    ifstream inFile("student_data.txt");
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    Student student;
    bool found = false;
    while (inFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber == rollNumberToDisplay) {
            found = true;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student with Roll Number " << rollNumberToDisplay << " not found." << endl;
    }

    inFile.close();
}

int main() {
    int choice, rollNumber;

    do {
        cout << "\nStudent Information Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Display Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                cout << "Enter Roll Number of student to delete: ";
                cin >> rollNumber;
                deleteStudent(rollNumber);
                break;
            case 3:
                cout << "Enter Roll Number of student to display: ";
                cin >> rollNumber;
                displayStudent(rollNumber);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
