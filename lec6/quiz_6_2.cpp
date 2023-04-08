#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Media {
public:
    virtual ~Media() {}
    virtual void describe() = 0;
};

class Book : public Media {
    private:
        string m_name;
        double m_price;

    public:
        Book(const string& name, double price)
            : m_name(name), m_price(price) {}

        void describe() override {
            cout << "Book: " << m_name << ", Price: " << m_price << '\n';
        }
};

class CD : public Media {
    private:
        int m_id;
        double m_price;

    public:
        CD(int id, double price)
            : m_id(id), m_price(price) {}

        void describe() override {
            cout << "CD: " << m_id << ", Price: " << m_price << '\n';
        }
};

class Library {
    private:
        string m_name;
        vector<Media*> m_media;

    public:
        Library(const string& name)
            : m_name(name) {}

        void addMedia(Media* media) {
            m_media.push_back(media);
        }

        void describe() {
            cout << "Library Name: " << m_name << endl;
            for (auto media : m_media) {
                media->describe();
            }
        }
};

int main() {
    Library library("My Library");
    Book book1("Book 1", 10.0);
    Book book2("Book 2", 15.0);
    book1.describe();

    CD cd1(12345, 20.0);
    library.addMedia(&book1);
    library.addMedia(&book2);
    library.addMedia(&cd1);
    library.describe();
    return 0;
}