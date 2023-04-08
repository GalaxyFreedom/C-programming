#include <iostream>
#include <string>
using namespace std;
class Vector2D{
    public:
        int x, y;
};
class Book{
    public:
        string id, author, title, genre, date, publisher,
        description;
        double price;
};
int add5(int& x){
    cout << "function x add:"<<&x<<endl;
    x=x+5;
    return x;
}
int& add3(int& number){
    number = number +3;
    cout << "number address 1: "<<&number<<endl;
    cout << "--------------------------------" << endl;
    return number;
}
int main ()
{
    /*
    Book book {"java101","Surbhi Kakar", "JavaProgramming",
    "Computer", "2010-08-01", "Dream Tech Press",
    "A description here", 30};
    cout << book.id<< endl;
    cout << book.author<< endl;
    cout << book.title<< endl;
    cout << book.genre<< endl;
    cout << book.date<< endl;
    cout << book.publisher<< endl;
    cout << book.description<< endl;
    cout << book.price<< endl;

    ----------------------------------
    int x=3;
    cout <<&x<<" "<<x<<endl;
    x = add5(x);
    cout <<&x<<" "<<x<<endl;
    */
   int number1=5;
   int& number2=add3(number1);

   cout << "Number1: "<<number1<<endl;
   cout << "Number2: "<<number2<<endl;

   cout << "Address1: "<<&number1<<endl;
   cout << "Address2: "<<&number2<<endl;

    return 0;
}