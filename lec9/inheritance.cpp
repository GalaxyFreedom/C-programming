#include <iostream>

using namespace std;

class Object {
public:
    Object() {}
    void describe() {
        cout << "I am a general object" << endl;
    }
};

// Animal is a derived class of Object
class Animal : public Object {
public:
    Animal() {}
    void wander() {
        cout << "I am wandering" << endl;
    }
};

// Cat is a derived class of Animal
class Cat : public Animal {
public:
    Cat() {}
    void sleep() {
        cout << "I am sleeping" << endl;
    }
};
int main() {
    Cat cat;
    cat.sleep();
    cat.wander();
    cat.describe();
    return 0;
}