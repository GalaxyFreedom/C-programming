#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    double salary;
public:
    Employee(){}
    ~Employee(){}
    Employee(string name, double salary) : name(name), salary(salary) {}
    string getName() { return name; }
    double getSalary() {
        cout << " salary is ";
        return salary;
    }
};

class Manager : public Employee {
private:
    double bonus;
public:
    Manager(){}
    ~Manager(){}
    Manager(string name, double salary, double bonus) : Employee(name, salary), bonus(bonus) {}
    double getSalary() { return Employee::getSalary() + bonus; }
};

int main() {
    Employee employee1("Peter", 60000.0);
    cout << employee1.getName() <<  employee1.getSalary() << endl;

    Manager manager2("Mary", 60000.0, 20000.0);
    cout << manager2.getName() << manager2.getSalary() << endl;
    return 0;
}