#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Person {
    private:
    public:
        virtual ~Person() {}
        virtual void print() = 0;
};

class Student : public Person {
    private:
        string m_name;
        int m_yearOfBirth;
        string m_grade;
    public:
        Student(const string& name, int yearOfBirth, string grade) :
            m_name(name), m_yearOfBirth(yearOfBirth), m_grade(grade) {}
        void print() override {
            cout << "Student name: " << m_name << "\n" <<
                " Year of Birth: " << m_yearOfBirth << "\n" <<
                " Grade: " << m_grade << "\n" << endl;
        }
};

class Teacher : public Person {
    private:
        string m_name;
        int m_yearOfBirth;
        string m_subject;
    public:
        Teacher(const string& name, int yearOfBirth, string subject) :
            m_name(name), m_yearOfBirth(yearOfBirth), m_subject(subject) {}
        void print() override {
            cout << "Teacher name: " << m_name << "\n" <<
            " Year of Birth: " << m_yearOfBirth << "\n" <<
            " Subject: " << m_subject << "\n" << endl;
        }
};

class Doctor : public Person {
    private:
        string m_name;
        int m_yearOfBirth;
        string m_specialist;
    public:
        Doctor(const string& name, int yearOfBirth, string specialist) :
            m_name(name), m_yearOfBirth(yearOfBirth), m_specialist(specialist) {}
        void print() override {
            cout << "Doctor name: " << m_name << "\n" <<
            " Year of Birth: " << m_yearOfBirth << "\n" <<
            " Specialist: " << m_specialist << "\n" << endl;
        }
};

class Ward {
    private:
        string m_name;
        vector<Person*> m_person;

    public:
        Ward(const string& name) : m_name(name) {}
        void addPerson(Person* person) {
            m_person.push_back(person);
        }
        void print() {
            cout << "Ward Name: " << m_name << endl;
            for (auto person : m_person) { person->print(); }
        }
        int countDoctor() {
            int count = 0;
            for (int i = 0; i < m_person.size(); i++) {
                if (dynamic_cast<Doctor*> (m_person[i])) {
                    count++;
                }
            }
            cout << "Doctor count: " << count << endl;
            return count;
        }
};

int main() {
    Student student1("Jane", 2000, "12");
    Teacher teacher1("John", 1970, "Math");
    Teacher teacher2("Mary", 1980, "History");
    Doctor doctor1("Jack", 1985, "Allergists");
    Doctor doctor2("Rose", 1980, "Dermatologists");
    Ward ward1("Ward 1");

    ward1.addPerson(&student1);
    ward1.addPerson(&teacher1);
    ward1.addPerson(&teacher2);
    ward1.addPerson(&doctor1);
    ward1.addPerson(&doctor2);

    ward1.print();
    ward1.countDoctor();
    return 0;
}