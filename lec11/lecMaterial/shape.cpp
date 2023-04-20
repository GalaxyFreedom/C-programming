#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Point {
protected:
    int m_x, m_y;
public:
    Point(int x, int y) : m_x(x), m_y(y) {}
    ~Point() = default;
    int getX() const { return m_x; }
    int getY() const { return m_y; }
    void print() const {
        cout << m_x << ", " << m_y << endl;
    }
};

class Shape {
private:
    string m_name;
    Point* m_point;
public:
    Shape(const string& name, int x, int y) : m_name(name), m_point(new Point(x, y)) {}
    virtual ~Shape() { delete m_point; };
    const string& getName() const { return m_name; }
    virtual void print() = 0;
};

class Circle : public Shape {
private:
    int m_radius;
public:
    Circle(const string& name, int radius, int x, int y) : Shape(name, x, y), m_radius(radius) {}
    ~Circle() {};
    void print() override {
        Shape::print();
        cout << " - Radius: " << m_radius << endl;
    }
};

class Rectangle : public Shape {
private:
    int m_length, m_width;
public:
    Rectangle(const string& name, int length, int width, int x, int y)
        : Shape(name, x, y), m_length(length), m_width(width) {}
    ~Rectangle() {};
    void print() override {
        Shape::print();
        cout << " - Length: " << m_length << " - Width " << m_width << endl;
    }
};

class Square : public Shape {
private:
    int m_side;
public:
    Square(const string& name, int side, int x, int y)
        : Shape(name, x, y), m_side(side) {}
    ~Square() {};
    void print() override {
        Shape::print();
        cout << " - Side: " << m_side << endl;
    }
};

class Canvas {
private:
    string m_name;
    vector<Shape*> m_shapes;
public:
    Canvas(const string& name) : m_name(name) {}
    ~Canvas() {}
    void add(Shape* shape) {
        m_shapes.push_back(shape);
    }
    void print() {
        for (int i = 0; i < m_shapes.size(); i++) {
            m_shapes[i]->print();
        }
    }
};

int main() {
    Square square1("Square 1", 10, 1, 2);
    Circle circle1("Circle 1", 4, 4, 5);
    Rectangle rectangle1("Rectangle 1", 8, 2, 7, 9);
    Canvas canvas1("Canvas 1");
    canvas1.add(&square1);
    canvas1.add(&circle1);
    canvas1.add(&rectangle1);

    square1.print();
    circle1.print();
    rectangle1.print();
    canvas1.print();
    return 0;
}
