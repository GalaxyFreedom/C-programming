#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Manufacturer {
private:
    int m_id;
    string m_location;
public:
    Manufacturer(int id, const string& location) : m_id(id), m_location(location) {}
    void describe() const {
        cout << " - Manufacturer ID: " << m_id
        << " Location: " << m_location << endl;
    }
};

class Device {
private:
    string m_name;
    double m_price;
    Manufacturer* m_manufacturer;
public:
    Device(const string& name, double price, int id, const string& location)
        : m_name(name), m_price(price), m_manufacturer(new Manufacturer(id, location)) {}
    void describe() const {
        cout << "Device Name: " << m_name
        << " Price: " << m_price;
        m_manufacturer->describe();
    }
};

int main() {
    Device d1 ("d 1", 12, 12345, "Vietnam");
    Device d2 ("d 2", 20, 12345, "Vietnam");
    d1.describe();
    d2.describe();
    return 0;
}