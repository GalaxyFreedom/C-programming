#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Media {
    public:
        virtual ~Media() {}
        virtual void print() = 0;
};

class CD  : public Media {
    private:
        int m_ID;
        double m_price;
    public:
        CD(int id, double price) : m_ID(id), m_price(price) {}
        void print() override {
            cout << "CD ID: " << m_ID << "; price: " << m_price << endl;
        }
};

class Book : public Media {
    private:
        string m_name;
        double m_price;
    public:
        Book(const string& name, double price) : m_name(name), m_price(price) {}
        void print() override {
            cout << "Book Name: " << m_name << "; price: " << m_price << endl;
        }
};

class Library {
    private:
        string m_name;
        vector<Media*> m_media;
    public:
        Library(const string& name) : m_name(name) {}

        void addMedia(Media* media) {
            m_media.push_back(media);
        }
        void print() const {
            cout << "Library Name: " << m_name << endl;
            auto count = 0;
            for (auto media : m_media) {
                media->print();
                count++;
                if (count > 0) { break; }
            }
        }
};
int main() {
    Library library("My library");
    Book book1("Book 1", 12);
    Book book2("Book 2", 12.5);
    book1.print();
    book2.print();

    CD cd1(12345, 20.0);
    library.addMedia(&book1);
    library.addMedia(&book2);
    library.addMedia(&cd1);
    library.print();
    return 0;
}