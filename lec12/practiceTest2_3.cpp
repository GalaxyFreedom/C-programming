#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Beverage {
private:
    float m_price;
    float m_toppingPrice;
    float m_condimentPrice;
public:
    Beverage() : m_price(0), m_toppingPrice(0), m_condimentPrice(0) {}
    Beverage(float price, float toppingPrice, float condimentPrice)
        : m_price(price), m_toppingPrice(toppingPrice), m_condimentPrice(condimentPrice) {}
    Beverage(const Beverage& other)
        : m_price(other.m_price), m_toppingPrice(other.m_toppingPrice), m_condimentPrice(other.m_condimentPrice) {}
    Beverage operator+(const Beverage& other) {
        Beverage result;
        result.m_price = m_price + other.m_price;
        result.m_toppingPrice = m_toppingPrice + other.m_toppingPrice;
        result.m_condimentPrice = m_condimentPrice + other.m_condimentPrice;
        return result;
    }
    bool operator==(const Beverage& other) const {
        if (m_price == other.m_price && m_toppingPrice == other.m_toppingPrice
            && m_condimentPrice == other.m_condimentPrice) {
                return true;
            }
        else {
            return false;
        }
    }
    void print() const {
        cout << "Price: " << m_price << " Topping Price: " << m_toppingPrice << " Condiment Price: " << m_toppingPrice << endl;
    }
};
int main() {
    Beverage b1 (10, 20, 30);
    Beverage b2 (20, 30, 40);
    Beverage b3(b1);
    b1.print();
    b2.print();
    b3.print();
    cout << "---------------------" << endl;
    b3 = b1 + b2;
    b3.print();
    cout << "Is b3 = b1? " << (b3 == b1) << endl;

    cout << "---------------------" << endl;
    b3 = b1;
    b3.print();
    cout << "Is b3 = b1? " << (b3 == b1) << endl;
}