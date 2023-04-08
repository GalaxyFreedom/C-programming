#include <iostream>
#include <string>

using namespace std;

struct Card{
    string cardID;
    string type;
};
struct Student{
    string name;
    Card card;
};

int main(){
    // print out "Hello world!"
    cout<<"Hello world!"<<endl;
    // integer
    int anInteger = 5;
    cout<< "Variable 1: "<<anInteger<<endl;
    // float
    float aFloat = 1.2f;
    cout<< "Variable 2: "<<aFloat<<endl;
    // double
    double aDouble = 3.14;
    cout<< "Variable 3: "<<aDouble<<endl;
    // boolean
    bool aBoolean = true;
    cout << "Variable 4: "<<aBoolean<<endl;
    //enter name
    string fullName;
    getline(cin, fullName);
    cout << "Your name is " <<fullName<<endl;

    struct Student s1;
    s1.name = "Nguyen Phuoc Thien Phu";
    s1.card.cardID="123";
    cout << s1.name<<endl;
    cout << s1.card.cardID<<endl;
    return 0;
}
