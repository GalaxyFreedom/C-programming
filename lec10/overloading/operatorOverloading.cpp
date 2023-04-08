#include <iostream>
#include <string>
using namespace std;
class Cat
{
private:
    string m_name;
    int m_age;
public:
    Cat(string name, int age) : m_name(name), m_age(age) {};

    void operator++() { m_age++; }

    void describe() {
        cout << "I am " << m_name << endl;
        cout << m_age << " years old" << endl;
    }
};

int main() {
    Cat bella("Bella", 2);
    bella.describe();

    ++bella;
    bella.describe();

}

