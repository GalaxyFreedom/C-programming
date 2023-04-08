#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Square {
private:
    string m_name;
    int m_side;
public:
    Square(string name, int side) : m_name(name), m_side(side) {}
    void describe() {
        cout << m_name << " is of side " << m_side << endl;
    }
    int getSide() { return m_side; }
};
bool compare(Square square1,Square square2) { return square1.getSide() < square2.getSide(); }

int main() {
    vector<Square> listOfSquares;
    Square square1 { "Square 1", 5 };
    Square square2 { "Square 2", 9 };
    Square square3 { "Square 3", 7 };

    listOfSquares.push_back(square1);
    listOfSquares.push_back(square2);
    listOfSquares.push_back(square3);

    sort(listOfSquares.begin(), listOfSquares.begin()+3, compare);
    for (int i = 0; i < listOfSquares.size(); i++) {
        listOfSquares[i].describe();
    }
}