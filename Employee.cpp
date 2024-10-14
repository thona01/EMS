#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Employee class definition
class Employee {
private:
    int id;
    string name;
    string position;
    double salary;

public:
    Employee(int empId, const string &empName, const string &empPosition, double empSalary)
        : id(empId), name(empName), position(empPosition), salary(empSalary) {}

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getPosition() const { return position; }
    double getSalary() const { return salary; }

    // Display employee details
    void display() const {
        cout << "ID: " << id << ", Name: " << name
             << ", Position: " << position << ", Salary: " << salary << endl;
    }
};

// Employee Management System class
class EmployeeManagementSystem {
private:
    vector<Employee> employees;

public:
    void addEmployee() {
        int id;
        string name, position;
        double salary;

        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin.ignore(); // Clear the newline character from the input buffer
        getline(cin, name);
        cout << "Enter Employee Position: ";
        getline(cin, position);
        cout << "Enter Employee Salary: ";
        cin >> salary;

        employees.emplace_back(id, name, position, salary);
        cout << "Employee added successfully!" << endl;
    }

    void viewEmployees() const {
        if (employees.empty()) {
            cout << "No employees found." << endl;
            return;
        }
        cout << "\nEmployee List:\n";
        for (const auto &employee : employees) {
            employee.display();
        }
    }

    void deleteEmployee() {
        int id;
        cout << "Enter Employee ID to delete: ";
        cin >> id;

        auto it = remove_if(employees.begin(), employees.end(),
            [id](const Employee &emp) { return emp.getId() == id; });

        if (it != employees.end()) {
            employees.erase(it, employees.end());
            cout << "Employee deleted successfully!" << endl;
        } else {
            cout << "Employee with ID " << id << " not found." << endl;
        }
    }
};

// Main function
int main() {
    EmployeeManagementSystem ems;
    int choice;

    do {
        cout << "\nEmployee Management System Menu:\n";
        cout << "1. Add Employee\n";
        cout << "2. View Employees\n";
        cout << "3. Delete Employee\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ems.addEmployee();
                break;
            case 2:
                ems.viewEmployees();
                break;
            case 3:
                ems.deleteEmployee();
                break;
            case 4:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
