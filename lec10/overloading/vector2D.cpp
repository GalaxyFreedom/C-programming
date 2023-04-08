#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vector2D {
private:
    int m_x, m_y;
public:
    Vector2D() {}
    Vector2D(int x, int y) : m_x(x), m_y(y) {}
    Vector2D operator-(const Vector2D& other) {
        Vector2D result;
        result.m_x = m_x - other.m_x;
        result.m_y = m_y - other.m_y;

        return result;
    }

    void describe() const {
        cout << "[" << m_x << ", " << m_y << "]" << endl;
    }

    Vector2D operator--(const int) {
        m_x--;
        m_y--;
        return Vector2D(m_x, m_y);
    }

    bool operator==(const Vector2D& other) {
        if (other.m_x != m_x && other.m_y != m_y) {
            return false;
        }
        else {
            return true;
        }
    }

    Vector2D operator*(const Vector2D& other) {
        Vector2D result;
        result.m_x = m_x * other.m_x;
        result.m_y = m_y * other.m_y;
        return result;
    }
};

int main() {
    Vector2D vector1 (1, 2);
    Vector2D vector2 (3, 4);
    cout << "Before: " << endl;
    vector1.describe();
    vector2.describe();

    Vector2D vector3 = vector1 - vector2;
    Vector2D vector4 = vector1 * vector2;
    vector1--;
    vector2--;

    cout << "After: " << endl;
    vector1.describe();
    vector2.describe();
    vector3.describe();
    vector4.describe();

}
