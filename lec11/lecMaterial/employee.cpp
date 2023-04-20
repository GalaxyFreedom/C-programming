#include <iostream>
#include <string>
#include <vector>

using namespace std;
class ID {
private:
    int m_number;
    string m_type;
public:
    ID() {}
    ID(int number, const string& type) : m_number(number), m_type(type) {}
    ~ID() {}
    int getNumber() const { return m_number; }
    const string& getType() const { return m_type; }
    void print() const {
        cout << "ID: " << m_number
            << " - ID type: " << m_type << endl;
    }
};

class Employee {
private:
    string m_name;
protected:
    double m_salary;
    ID* m_id;
public:
    Employee() {}
    Employee(const string& name, double salary, int idNumber, string idType) {
        m_name = name;
        m_salary = salary;
        m_id = new ID(idNumber, idType);
    }
    ~Employee() { delete m_id; }
    void print() const {
        cout << "Name: " << m_name << " - ";
        m_id->print();
    }
};

class Manager : public Employee {
private:
    double m_bonus;
public:
    Manager() {}
    Manager(const string& name, double salary, double bonus, int idNumber, string idType)
            : Employee(name, salary, idNumber, idType), m_bonus(bonus) {}

    void print() const {
        Employee::print();
        cout << " - bonus: " << m_bonus << endl;
    }
};

int main() {
    Employee employee1("Peter",50,12345,"type 1");
    Manager manager1("Mary",50,20,56789,"type 2");
    
    employee1.print();
    manager1.print();
    return 0;
}