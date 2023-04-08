#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Shape {
    public:
        virtual double getArea() = 0;
};
class Square : public Shape {
    private:
        int side;
    public:
        Square(){}
        ~Square(){}
        Square(int side) : side(side) {}
        double getArea() {
            cout << "Area of square: ";
            return side*side;
        }
};
class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(){}
        ~Circle(){}
        Circle(double radius) : radius(radius) {}
        double getArea() {
            cout << "Area of circle: ";
            return radius*radius*M_PI;
        }
};
class Rectangle : public Shape {
    private:
        double length, width;
    public:
        Rectangle(){}
        ~Rectangle(){}
        Rectangle(double length, double width) : length(length), width(width) {}
        double getArea() {
            cout << "Area of rectangle: ";
            return length*width;
        }
};
int main() {
    Square square(5);
    cout << square.getArea() << endl;

    Rectangle rectangle(5, 4);
    cout << rectangle.getArea() << endl;

    Circle circle(6);
    cout << circle.getArea() << endl;

    return 0;
}
