#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Shape {
public:
    virtual void describe() = 0;
    virtual double perimeter() = 0;
    virtual double area() = 0;
};

class Circle : public Shape {
private:
    string m_name;
    double m_radius;
public:
    Circle(const string& name, double radius) : m_name(name), m_radius(radius) {}
    void describe() override {
        cout << "Circle: " << m_name << " has radius of " << m_radius << endl;
    }
    double perimeter() override { return m_radius*2*3.14; }
    double area() override { return m_radius*m_radius*3.14; }
};

class Square : public Shape {
private:
    string m_name;
    double side;
public:
    Square(const string& name, double side) : m_name(name), side(side) {}
    void describe() override {
        cout << "Square: " << m_name << " has side " << side << endl;
    }
    double perimeter() override { return side*4; }
    double area() override { return side*side; }
};

bool compare(Shape* s1, Shape* s2) {
    return s1->area() < s2->area();
}

class Canvas {
private:
    string name;
    vector<Shape*> shapes;
public:
    Canvas(const string& name) : name(name) {}
    void add(Shape* shape) {
        shapes.push_back(shape);
    }
    void describe() {
        for (int i = 0; i < shapes.size(); i++) {
            shapes[i]->describe();
        }
    }
    int countCircle() {
        int count = 0;
        for(int i = 0; i < shapes.size(); i++) {
            if (dynamic_cast<Circle*>(shapes[i])) {
                count++;
            }
        }
        return count;
    }
    void sortByArea() {
        sort(shapes.begin(), shapes.end(), compare);
    }
    int countNumberOfCircle() {
        int count = 0;
        for (int i = 0; i < shapes.size(); i++) {
            if (Shape* circle = dynamic_cast <Circle*> (shapes[i])){
                count++;
            }
        }
        return count;
    }
    double computeTotalSquareArea() {
        double result = 0;
        for (int i = 0; i < shapes.size(); i++) {
            if (Shape* square = dynamic_cast <Square*> (shapes[i])) {
                result += square->area();
            }
        }
        return result;
    }
};

int main() {
    Circle circle1 { "circle 1", 3 };
    Circle circle2 { "circle 2", 4 };
    Square square1 { "square 1", 5 };
    Square square2 { "square 2", 6 };
    Canvas canvas1 { "canvas 1" };

    canvas1.add(&circle1);
    canvas1.add(&circle2);
    canvas1.add(&square1);
    canvas1.add(&square2);

    // print canvas1
    canvas1.describe();
    cout << "------------------------------" << endl;

    // sort shapes by area
    canvas1.sortByArea();
    canvas1.describe();
    cout << "------------------------------" << endl;

    // count number of Circles
    cout << "number of Circles: " << canvas1.countNumberOfCircle() << endl;
    cout << "------------------------------" << endl;

    // compute total area of Squares
    cout << "total area of Squares: " << canvas1.computeTotalSquareArea() << endl;
}