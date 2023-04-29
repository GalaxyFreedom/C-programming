#include <iostream>
#include <string>

using namespace std;

template<class  T> class Data{
private:
    T m_value1;
    T m_value2;
public:
    Data(const T& value1, const T& value2) : m_value1(value1), m_value2(value2) {}
    T sum() { return m_value1 + m_value2; }
};

class Rectangle {
private:
    double m_length, m_width;
public:
    Rectangle(double length, double width) : m_length(length), m_width(width) {}
    Rectangle operator+(const Rectangle& other) const {
        Rectangle result(m_length + other.m_length, m_width + other.m_width);
        return result;
    }
    void describe() const {
        cout << "Rectangle: ";
        cout << "Length: " << m_length << ", Width: " << m_width << endl;
    }
};

int main() {
    Rectangle rectangle1(1,2);
    Rectangle rectangle2(3,4);
    Data<Rectangle> rectangleData(rectangle1, rectangle2);
    Rectangle sumRectangle = rectangleData.sum();
    sumRectangle.describe();
    return 0;
}