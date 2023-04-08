#include <iostream>
#include <string>
using namespace std;

class Person {
    private:
        string name;
        int yearOfBirth;
    public:
        Person() {}
        ~Person() {}
        Person(string name, int yearOfBirth) : name(name), yearOfBirth(yearOfBirth) {}
        bool checkName(const Person& person) { return person.name == name; }
        bool checkYearOfBirth(const Person& person) { return person.yearOfBirth == yearOfBirth; }
        void print() { cout << "Name: " << name << endl << " Year of Birth: " << yearOfBirth << endl; }
        void copyName(const Person& person) { name = person.name; }
};

int main() {
    Person person1{ "Peter", 2000 }, person2{ "John",  2000}, person3;
    person1.print();
    person2.print();

    bool checkName = person1.checkName(person2);
    if (checkName != true)
        cout << "They are not of the same name. " << endl;
    else
        cout << "They are of the same name." << endl;

    bool checkAge = person1.checkYearOfBirth(person2);
    if (checkAge != true)
        cout << "They are not of the same age." << endl;
    else
        cout << "They are of the same age." << endl;

    person3.copyName(person1);
    person3.print();
}