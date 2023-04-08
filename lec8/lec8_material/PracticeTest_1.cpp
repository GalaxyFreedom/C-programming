#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Point {
    public:
        int m_x,m_y;
        Point(int x, int y) : m_x(x), m_y(y) {}
        void print() const {
            cout << "Center point " << m_x << ", " << m_y;
        }
};

class Shape {
    private:
        Point centerPoint;
    public:
        Shape(int x, int y) : centerPoint(x,y) {}
        void print() const {
            centerPoint.print();
        };
        void distance(const Shape& other) const {
            cout << "Distance: "
            << sqrt( pow(centerPoint.m_x - other.centerPoint.m_x,2) + pow(centerPoint.m_y - other.centerPoint.m_y,2) ) << endl;
        }
        virtual double area() = 0;
        virtual double perimeter() = 0;
        static double totalArea(vector<Shape*>& shapes)  {
            double totalArea = 0;
            for(int i = 0; i < shapes.size(); i++) {
                totalArea += shapes[i]->area();
            }
            return totalArea;
        }
};
bool compare(Shape* s1, Shape* s2) {
    return s1->perimeter() < s2->perimeter();
}

class Circle : public Shape {
    private:
        int m_radius;

    public:
        Circle(int x, int y, int radius) : Shape(x,y), m_radius(radius) {}
        void print() const {
            cout << "Circle ";
            Shape::print();
            cout << "; " << "radius: " << m_radius << endl;
        }
        double perimeter() {
            return 2*m_radius*3.14;
        }
        double area() {
            return pow(m_radius,2)*3.14;
        }
};

class Square : public Shape {
    private:
        int m_side;
    public:
        Square(int x, int y, int side) : Shape(x,y), m_side(side) {}
        void print() const {
            cout << "Square " ;
            Shape::print();
            cout << "; " << "side: " << m_side << endl;
        }
        double perimeter() {
            return m_side*4;
        }
        double area() {
            return m_side*m_side;
        }
};


class Rectangle : public Shape {
    private:
        int m_height, m_width;
    public:
        Rectangle(int x, int y, int height, int width) : Shape(x,y), m_height(height), m_width(width) {}
        void print() const {
            cout << "Rectangle ";
            Shape::print();
            cout << "; " << "height: " << m_height << " width: " << m_width <<endl;
        }
        double perimeter() {
            return (m_height+m_width)*2;
        }
        double area() {
            return m_height*m_width;
        }
};


int main() {
    Circle circle(1,2,3);
    Square square(3,4,5);
    Rectangle rectangle(4,6,6,3);
    vector <Shape*> shapes;
    shapes.push_back(&circle);
    shapes.push_back(&square);
    shapes.push_back(&rectangle);


    circle.print();
    square.print();
    rectangle.print();

    circle.distance(square);

    sort(shapes.begin(), shapes.end(), compare);
    for(int i=0; i<shapes.size(); i++) {
        cout << shapes[i]->perimeter() << " " << endl;
    }
    int totalSquaresAreas = 0;
    for (int i=0; i<shapes.size(); i++) {

        if(dynamic_cast<Square*> (shapes[i])) {
            totalSquaresAreas += shapes[i]->area();
        }
    }
    cout << "Total Square Area: " << totalSquaresAreas << endl;


    return 0;
}