#include <iostream>
#include <string>

using namespace std;

class Employee {
    private:
        int employeeId;
        string employeeName;
        string gender;
        int age;
        string address;
        int salary;
    public:
        void setEmployeeId(int employeeId) { this->employeeId = employeeId; }
        void setEmployeeName(string employeeName) { this->employeeName = employeeName; }
        void setGender(string genderType) { gender = genderType; }
        void setAge(int age) { this->age = age; }
        void setAddress(string address) { this->address = address; }
        void setSalary(int salary) { this->salary = salary; }

        int getEmployeeId() { return employeeId; }
        string getEmployeeName() { return employeeName; }
        string getGender() { return gender; }
        int getAge() { return age; }
        string getAddress() { return address; }
        int getSalary() { return salary; }

        void printInfo(Employee employee) {
            cout << "Employee Id: " << employeeId << endl;
            cout << "Employee Name: " << employeeName << endl;
            cout << "Gender: " << gender << endl;
            cout << "Age: " << age << endl;
            cout << "Address: " << address << endl;
            cout << "Salary: " << salary << endl;
            cout << endl;
        }
        void printHello();
};
void Employee::printHello() {
    cout << "Hello World!" << endl;
}
int main() {
    Employee employee1, employee2;
    employee1.setEmployeeId(1);
    employee1.setEmployeeName("John");
    employee1.setGender("Male");
    employee1.setAge(20);
    employee1.setAddress("1234");
    employee1.setSalary(1000);

    employee2.setEmployeeId(2);
    employee2.setEmployeeName("Maria");
    employee2.setGender("Female");
    employee2.setAge(21);
    employee2.setAddress("5678");
    employee2.setSalary(2000);

    employee1.printInfo(employee1);
    employee2.printInfo(employee2);
    employee1.printHello();
    return 0;
}