#include <iostream>
#include <string>

using namespace std;

class Cat{
    private:
        int index=0;
        int age;
        string names[3];
        string color;
    public:
        void addName(string name) {
            if (index < 3){
                this->names[index] = name;
                index++;
            }
        };
        void printName() {
            for (int i = 0 ; i <= index; i++){
                cout << names[i] << endl;
            }
        }
        void getColor() { cout << color << endl;};
        void setColor(string color) { this->color = color; };

        void getAge() { cout << age << endl;}
        void setAge(int age) { this->age = age; }
};

int main() {
    Cat cat;
    cat.addName("John");
    cat.printName();
    cat.addName("Tom");
    cat.printName();
    cat.addName("Jack");
    cat.printName();
}