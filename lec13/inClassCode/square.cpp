#include <iostream>
#include <string>

using namespace std;
class Square {
private:
    int m_side;
public:
    Square() = default;
    Square(int side) : m_side(side) {}
    Square operator+(const Square& other) {
        Square result(m_side + other.m_side);
        return result;
    }

    Square operator-(const Square& other) {
        Square result(m_side - other.m_side);
        return result;
    }

    void describe() const {
        cout << "Side: " << m_side << endl;
    }
};

class Vector {
private:
    int m_x, m_y;
public:
    Vector() = default;
    Vector(int x, int y) : m_x(x), m_y(y) {}
    Vector operator+(const Vector& other) {
        Vector result(m_x + other.m_x, m_y + other.m_y);
        return result;
    }
    Vector operator-(const Vector& other) {
        Vector result(m_x - other.m_x, m_y - other.m_y);
        return result;
    }
    void describe() const {
        cout << " (" << m_x << ", " << m_y << ") " << endl;
    }
};
template<class T> class Data {
private:
    T m_value1;
    T m_value2;
public:
    Data(T value1, T value2) : m_value1(value1), m_value2(value2) {}
    T sum() {
        return m_value1 + m_value2;
    }

    T subtract() {
        return m_value1 - m_value2;
    }
};

int main() {
    Data<int> intData(5, 6);
    cout << "sum1: " << intData.sum() << endl;

    string s1 = "C++";
    string s2 = "Programming";
    Data<string> stringData(s1, s2);
    cout << "sum2: " << stringData.sum() << endl;

    Square square1(10);
    Square square2(7);
    Data<Square> squareData(square1, square2);
    Square sumSquare = squareData.sum();
    Square subtractSquare = squareData.subtract();
    cout << "sumSquare: ";
    sumSquare.describe();
    cout << "subtractSquare: ";
    subtractSquare.describe();

    Vector vector1( 2, 4 );
    Vector vector2( 1, 0 );
    Data<Vector> vectorData(vector1, vector2);
    Vector sumVector = vectorData.sum();
    Vector subtractVector = vectorData.subtract();
    cout << "sumVector: ";
    sumVector.describe();
    cout << "subtractVector: ";
    subtractVector.describe();

    return 0;
}