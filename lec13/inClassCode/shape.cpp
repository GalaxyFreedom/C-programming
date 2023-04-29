#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T> class Data {
private:
    T m_value1;
    T m_value2;
public:
    Data(const T& value1, const T& value2) : m_value1(value1), m_value2(value2) {}
    T sum() { return m_value1 + m_value2; }
    T subtract() { return m_value1 - m_value2; }
};

class Shape {
public:
    virtual const double perimeter() = 0;
    virtual const double area() = 0;
    virtual void describe() = 0;
};

class Square : public Shape {
private:
    string m_name;
    double m_side;
public:
    Square() = default;
    Square(const string& name, double side) : m_name(name), m_side(side) {}

    const double getSide() const { return m_side; }
    const double perimeter() override { return 4 * m_side; }
    const double area() override { return m_side * m_side; }
    Square* add(double value) {
        m_side += value;
        return this;
    }



    void describe() override {
        cout << "Square: ";
        cout << "Side: " << m_side << endl;
    }
};

class Circle : public Shape {
private:
    string m_name;
    double m_pi = 3.14159265359;
    double m_radius;

public:
    Circle(const string& name, double radius) : m_radius(radius), m_name(name) {}

    void setRadius(double radius) { m_radius = radius; }

    const double getRadius() const { return m_radius; }
    const double perimeter() override { return 2 * m_pi * m_radius; }
    const double area() override { return m_pi * m_radius * m_radius; }
    Circle* add(double value) {
        m_radius += value;
        return this;
    }

    // overloading operator+ to add 2 Circle objects
    Circle operator+(const Circle& other) {
        Circle result("sumCircle", m_radius + other.m_radius);
        return result;
    }

    Circle operator-(const Circle& other) {
        Circle result("subtractCircle", m_radius - other.m_radius);
        return result;
    }

    void describe() override {
        cout << m_name;
        cout << ": radius: " << m_radius << endl;
    }
};

bool compare(Shape* s1, Shape* s2) {
    return s1->area() < s2->area();
}

class Canvas {
private:
    string m_name;
    vector<Shape*> shapes;
public:
    Canvas(const string& name) : m_name(name) {}
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    void describe() const {
        for (int i = 0; i < shapes.size(); i++) {
            shapes[i]->describe();
        }
    }

    int countCircle() {
        int count = 0;
        for (int i = 0; i < shapes.size(); i++) {
            if (dynamic_cast<Circle*>(shapes[i])) {
                count++;
            }
        }
        return count;
    }

    void sortByArea() {
        sort(shapes.begin(), shapes.end(), compare);
    }
};

int main() {
    Circle circle1("Circle 1",3);
    circle1.add(1);
    Circle circle2("Circle 2",2);
    Circle circle3("Circle 3",10);
    Square square1("Square 1",5);
    Square square2("Square 2",9);

    Data<Circle> circleData(circle1, circle2);
    Circle sumCircle = circleData.sum();
    sumCircle.describe();

    Canvas canvas("Canvas 1");
    canvas.addShape(&circle1);
    canvas.addShape(&circle2);
    canvas.addShape(&circle3);
    canvas.addShape(&square1);
    canvas.addShape(&square2);

    cout << endl;
    canvas.describe();

    cout << endl;
    cout << "Circle count: "<< canvas.countCircle() << endl;

    cout << "\nSorted by Area: " << endl;
    canvas.sortByArea();
    canvas.describe();
    cout << endl;
}
