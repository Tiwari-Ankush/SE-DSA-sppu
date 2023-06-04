// Company maintains employee information as employee ID, name, designation and
// salary. Allow user to add, delete information of employee. Display information of
// particular employee. If employee does not exist an appropriate message is displayed. If
// it is, then the system displays the employee details. Use index sequential file to maintain
// the data.

#include <iostream>
#include <fstream>

using namespace std;

// Structure to store employee information
struct Employee
{
    int employeeID;
    char name[50];
    char designation[50];
    int salary;
};

// Function to add employee information
void addEmployee()
{
    ofstream file("employees.data", ios::binary | ios::app);

    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    Employee emp;

    cout << "Enter Employee ID: ";
    cin >> emp.employeeID;

    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(emp.name, 50);

    cout << "Enter Designation: ";
    cin.getline(emp.designation, 50);

    cout << "Enter Salary: ";
    cin >> emp.salary;

    file.write(reinterpret_cast<char *>(&emp), sizeof(Employee));
    file.close();

    cout << "Employee information added successfully!" << endl;
}

// Function to delete employee information
void deleteEmployee()
{
    int empID;
    cout << "Enter Employee ID to delete: ";
    cin >> empID;

    ifstream file("employees.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    if (!file || !temp)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    Employee emp;
    bool found = false;

    while (file.read(reinterpret_cast<char *>(&emp), sizeof(Employee)))
    {
        if (emp.employeeID != empID)
        {
            temp.write(reinterpret_cast<char *>(&emp), sizeof(Employee));
        }
        else
        {
            found = true;
        }
    }

    file.close();
    temp.close();

    if (!found)
    {
        cout << "Employee not found!" << endl;
        remove("temp.dat");
    }
    else
    {
        remove("employees.dat");
        rename("temp.dat", "employees.dat");
        cout << "Employee information deleted successfully!" << endl;
    }
}

// Function to display employee information
void displayEmployee()
{
    int empID;
    cout << "Enter Employee ID to display: ";
    cin >> empID;

    ifstream file("employees.dat", ios::binary);

    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    Employee emp;
    bool found = false;

    while (file.read(reinterpret_cast<char *>(&emp), sizeof(Employee)))
    {
        if (emp.employeeID == empID)
        {
            cout << "Employee ID: " << emp.employeeID << endl;
            cout << "Name: " << emp.name << endl;
            cout << "Designation: " << emp.designation << endl;
            cout << "Salary: " << emp.salary << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Employee not found!" << endl;
    }

    file.close();
}

void displayAllEmployees()
{
    ifstream file("employees.dat", ios::binary);

    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    Employee emp;

    cout << "Employee Details:\n";
    cout << "-----------------\n";

    while (file.read(reinterpret_cast<char *>(&emp), sizeof(Employee)))
    {
        cout << "Employee ID: " << emp.employeeID << endl;
        cout << "Name: " << emp.name << endl;
        cout << "Designation: " << emp.designation << endl;
        cout << "Salary: " << emp.salary << endl;
        cout << "-----------------\n";
    }

    file.close();
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\nEmployee Management System" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display Employee" << endl;
        cout << "4. Display all employees" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addEmployee();
            break;
        case 2:
            deleteEmployee();
            break;
        case 3:
            displayEmployee();
            break;
        case 4:
            displayAllEmployees();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }

    return 0;
}
