#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Employee structure
struct Employee {
    int id;
    string name;
    string designation;
    double salary;
};

// Index structure
struct Index {
    int id;
    long position; // Position of the record in the data file
};

// Function to add employee information to the data file and update the index file
void addEmployee(Index &index) {
    ofstream dataFile("employee_data.txt", ios::app);
    ofstream indexFile("employee_index.txt", ios::app | ios::binary);

    if (!dataFile || !indexFile) {
        cerr << "Error opening files." << endl;
        return;
    }

    Employee newEmployee;

    cout << "Enter Employee ID: ";
    cin >> newEmployee.id;
    cout << "Enter Name: ";
    cin.ignore(); // Ignore the newline character left in the stream
    getline(cin, newEmployee.name);
    cout << "Enter Designation: ";
    getline(cin, newEmployee.designation);
    cout << "Enter Salary: ";
    cin >> newEmployee.salary;

    // Writing data to the data file
    dataFile << newEmployee.id << "," << newEmployee.name << "," << newEmployee.designation << "," << newEmployee.salary << endl;

    // Writing index to the index file
    index.id = newEmployee.id;
    index.position = dataFile.tellp(); // Get the current position in the data file
    indexFile.write(reinterpret_cast<char*>(&index), sizeof(Index));

    cout << "Employee information added successfully." << endl;

    dataFile.close();
    indexFile.close();
}

// Function to display information of a particular employee
void displayEmployee(int id) {
    ifstream dataFile("employee_data.txt");
    ifstream indexFile("employee_index.txt", ios::binary);

    if (!dataFile || !indexFile) {
        cerr << "Error opening files." << endl;
        return;
    }

    Index index;
    Employee employee;
    bool found = false;

    while (indexFile.read(reinterpret_cast<char*>(&index), sizeof(Index))) {
        if (index.id == id) {
            found = true;
            // Move to the position of the record in the data file
            dataFile.seekg(index.position, ios::beg);
            // Read the employee data from the data file
            dataFile >> employee.id;
            dataFile.ignore(); // Ignore the comma separator
            getline(dataFile, employee.name, ',');
            getline(dataFile, employee.designation, ',');
            dataFile >> employee.salary;

            cout << "Employee ID: " << employee.id << endl;
            cout << "Name: " << employee.name << endl;
            cout << "Designation: " << employee.designation << endl;
            cout << "Salary: " << employee.salary << endl;
            break;
        }
    }

    if (!found) {
        cout << "Employee with ID " << id << " not found." << endl;
    }

    dataFile.close();
    indexFile.close();
}

int main() {
    int choice, id;
    Index index;

    do {
        cout << "\nEmployee Information Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employee\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee(index);
                break;
            case 2:
                cout << "Enter Employee ID: ";
                cin >> id;
                displayEmployee(id);
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
