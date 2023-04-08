#include <iostream>
#include <string>

using namespace std;
class Person {
    private:
        string name;
        int yearOfBirth;
    public:
        Person() : name{""}, yearOfBirth{} {}
        Person(string name, int yearOfBirth) : name{name}, yearOfBirth{yearOfBirth} {}
        ~Person() {}

        void print() {
            cout << "Name: " << name << endl;
            cout << "Year of birth: " << yearOfBirth << endl;
            cout << "------------------------------------------------";
        }
};

class Ward {
    private:
        string name;
        Person *list;
        int size;
        int index=0;
    public:
        Ward(string name, int size) : name{name}, size{size} { list = new Person[size]; }
        void addPerson(Person person) {
            if (index < size) {
                list[index] = person;
                index++;
            }
        }
        void print() {
            for (int i=0; i<index;  i++) {
                list[i].print();
                cout << endl;
            }
        }
        ~Ward() { delete[] list; }
};

int main() {
    Person person1{ "Jack", 2000 },
    person2{ "John", 2000 };
    Ward ward1{ "One", 10};
    ward1.addPerson(person1);
    ward1.addPerson(person2);
    ward1.print();
}