#include <iostream>
#include <string>

using namespace std;
class Author {
private:
    string m_authorName;
    int m_yearOfBirth;
public:
    Author() = default;
    Author(const string& authorName, int yearOfBirth) : m_authorName(authorName), m_yearOfBirth(yearOfBirth) {}
    void describe() const {
        cout << "Author name: " << m_authorName << ", Year of birth: " << m_yearOfBirth << endl;
    }
};
class Book {
private:
    string m_bookName;
    Author* m_author;
public:
    Book(const string& bookName, const string& authorName, int yearOfBirth) : m_bookName(bookName), m_author(new Author(authorName, yearOfBirth)) {}
    void describe() const {
        cout << "Book name: " << m_bookName << ", ";
        m_author->describe();
    }
};

int main() {
    Book book1("C++ Programming", "Jack", 1980);
    book1.describe();
}