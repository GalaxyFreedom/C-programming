#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
private:
    int m_day;
    int m_month;
    int m_year;
public:
    // constructor
    Date() {}
    Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {}

    // get methods
    int getDay() { return m_day; }
    int getMonth() { return m_month; }
    int getYear() { return m_year; }

    // describe the date of birth
    void describe() {
        cout << "date of birth: " << m_day << "/" << m_month << "/" << m_year <<endl;
    }

    // save the date to the file
    void save(ofstream& os) {
        os << m_day << "/" << m_month << "/" << m_year;
    }
};

class Person : public Date {
private:
    string m_name;
    Date m_dateOfBirth;
public:
    // default constructor
    Person() {}
    Person(const string& name, int day, int month, int year) : m_name(name), m_dateOfBirth(day, month, year) {}

    // get method
    string getName() { return m_name; }

    // describe
    void describe() {
        cout << "Name: " << m_name << endl;
        m_dateOfBirth.describe();
    }

    // check same name
    bool checkSameName(string name) {
        if (name != m_name) {
            return false;
        }
        else {
            return true;
        }
    }

    // check same age
    bool checkSameAge(Date dateOfBirth) {
        if ( dateOfBirth.getDay() != m_dateOfBirth.getDay()
            && dateOfBirth.getMonth() != m_dateOfBirth.getMonth()
            && dateOfBirth.getYear() != m_dateOfBirth.getYear() ) {
            return false;
        }
        else {
            return true;
        }
    }

    // write the name and the date of birth to the
    // <string dir> file name
    void save(string dir) {
        ofstream outputFile(dir, ios::app);
        outputFile << m_name << ", ";
        m_dateOfBirth.save(outputFile);
        outputFile << endl;
        outputFile.close();
    }
};

class List : public Person {
private:
    int count = 0;
    string m_name;
    vector<Person*> m_people;
public:
    // default constructor
    List(const string& name) : m_name(name) {}
    void addPerson(Person* person) {
        m_people.push_back(person);
        count++;
    }

    // describe
    void describe() {
        for (int i = 0; i < count; i++) {
            m_people[i]->describe();
        }
    }


    // get method
    int getCount() const { return count; }

    // save Person from m_people to <string dir> file
    void save(string dir) {
        for (int i = 0; i < count; i++) {
            m_people[i]->save(dir);
        }
    }
};

int main() {
    // define person
    Person person1 {"John", 10, 1, 2000};
    Person person2 {"Maria", 10, 2, 2000};
    Person person3 {"Jack", 10, 3, 2000};

    // define list of people
    List listOfPeople {"list 1"};
    // add people to list
    listOfPeople.addPerson(&person1);
    listOfPeople.addPerson(&person2);
    listOfPeople.addPerson(&person3);

    // check if 2 people have the same age
    bool check = person1.checkSameAge(person2);
    if (check != true) {
        cout << person1.getName() << " is not the same age as " << person2.getName() << endl;
    }
    else {
        cout << person1.getName() << " is the same age as " << person2.getName() << endl;
    }

    // check if 2 people have the same name
    check = person1.checkSameName(person2.getName());
    if (check != true) {
        cout << person1.getName() << "  does not have the same name as " << person2.getName() << endl;
    }
    else {
        cout << person1.getName() << " has the same name as " << person2.getName() << endl;
    }


    // save the list of people to txt
    listOfPeople.save("file_class.txt");
}