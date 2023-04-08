#include <iostream>
#include <string>
using namespace std;

class MyClass {
public:
    void myFunction() {
        cout << "Some content in parent class." << endl;
    }
};
class MyOtherClass {
public:
    void myOtherFunction() {
        cout << "Some content in another class" << endl;
    }
};
class MyChildClass : public MyClass, public MyOtherClass {};

int main() {
    MyChildClass myObj;
    myObj.myFunction();
    myObj.myOtherFunction();
    return 0;
}