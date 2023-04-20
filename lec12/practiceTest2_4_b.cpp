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
    Date() = default;
    Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {}
    void print() const {
        cout << " Day " << m_day << " month " << m_month << " year " << m_year << endl;
    }
};
class Book {
private:
    string m_name;
    string m_author;
    Date* m_publicationDate;
public:
    Book() = default;
    Book(const string& name, const string& author, Date* publicationDate)
        : m_name(name), m_author(author), m_publicationDate(publicationDate) {}
    void print() const {
        cout << "Book name: " << m_name << " Author: " <<  m_author << endl;
        m_publicationDate->print();
    }
};

int main() {
    Date publicationDate(27, 6, 2022);
    Book book("C++", "Peter", &publicationDate);
    book.print();
    return 0;
}