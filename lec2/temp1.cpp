#include <iostream>
#include <string>
using namespace std;

class Cat{
    private:
        string name;
    public:
        void setName(string inputName) { name = inputName; }
        string getName() { return name; }
};

class Book{
    private:
        string id, author, title, genre, publishDate,
        publisher, description;
        double price;
    public:
        void setId(string idName) { id = idName; }
        void setAuthor(string authorName) { author = authorName; }
        void setTitle(string titleName) { title = titleName; }
        void setGenre(string genreName) { genre = genreName; }
        void setPublishDate(string publishDateString) { publishDate = publishDateString; }
        void setPublisher(string publisherName) { publisher = publisherName; }
        void setDescription(string descriptionString) { description = descriptionString; }
        void setPrice(double priceTag) { price = priceTag; }

        string getId() { return id; }
        string getAuthor() { return author; }
        string getTitle() { return title; }
        string getGenre() { return genre; }
        string getPublishDate() { return publishDate; }
        string getPublisher() { return publisher; }
        string getDescription() { return description; }
        double getPrice() { return price; }
};
int main() {
    /*    Cat cat;
    cat.setName("Calico");
    cout << cat.getName() << endl;*/
    Book book;
    book.setId("java101");
    book.setAuthor("Surbhi Kakar");
    book.setTitle("Java Programming");
    book.setGenre("Computer");
    book.setPublishDate("2010-08-01");
    book.setPublisher("Dream Tech Press");
    book.setDescription("A description here.");
    book.setPrice(30.0);

    cout << book.getId() << endl;
    cout << book.getAuthor() << endl;
    cout << book.getTitle() << endl;
    cout << book.getGenre() << endl;
    cout << book.getPublishDate() << endl;
    cout << book.getPublisher() << endl;
    cout << book.getDescription() << endl;
    cout << book.getPrice() << endl;
    return 0;
}
