#include <iostream>
#include <string>

using namespace std;

class Author {
private:
    string m_authorName;
    int m_yearOfBirth;
public:
    Author() = default;
    Author(const string& authorName, int yearOfBirth) : m_authorName(authorName), m_yearOfBirth(yearOfBirth){}
    void describe() const {
        cout << "Author Name: " << m_authorName << ", Year of Birth: " << m_yearOfBirth << endl;
    }
};

class Book {
private:
    string m_bookName;
    Author* m_author;
public:
    Book() = default;
    Book(const string& bookName, Author* author) : m_bookName(bookName), m_author(author) {}
    ~Book() { delete m_author; }
    void describe() const {
        cout << "Book Name: " << m_bookName;
        m_author->describe();
    }
};

int main() {
    Author author1("Jack", 1980);
    Book book1("C++ Programming", &author1);
    book1.describe();
    return 0;
}