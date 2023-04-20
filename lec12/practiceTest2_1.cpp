#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Complex {
private:
    float m_real;
    float m_imag;
public:
    Complex() = default;
    Complex(float real, float imag) : m_real(real), m_imag(imag) {}
    ~Complex() {}
    Complex(const Complex& other) : m_real(other.m_real), m_imag(other.m_imag) {}
    Complex operator+(const Complex& other) {
        Complex result;
        result.m_real = m_real + other.m_real;
        result.m_imag = m_imag + other.m_imag;
        return result;
    }
    bool operator==(const Complex& other) const {
        if (m_real == other.m_real && m_imag == other.m_imag) {
            return true;
        }
        else return false;
    }
    Complex operator=(const Complex& other) {
        m_real = other.m_real;
        m_imag = other.m_imag;
        return *this;
    }
    void print() const {
        cout << m_real << ", " << m_imag << endl;
    }
};
int main() {
    Complex num1(1.2,3.2);
    Complex num2(5.3,2.7);
    Complex num3(num2);
    num1.print();
    num2.print();
    num3.print();
    cout << "-------------------" << endl;
    num3 = num1 + num2;
    num3.print();
    cout << "-------------------" << endl;
    num3 = num1;
    num3.print();
    cout << "-------------------" << endl;
    if (num3 == num1) {
        cout << "2 complex numbers are equal!" << endl;
    }
    else {
        cout << "2 complex numbers are not equal!" << endl;
    }
}