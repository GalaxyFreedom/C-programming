#include <iostream>
#include <queue>

using namespace std;

class Square {
private:
    string m_name;
    int m_side;
public:
    Square() = default;
    Square(const string& name, int side) : m_name(name), m_side(side) {}
    void describe() const {
        cout << m_name << " is of side " << m_side << endl;
    }
};
int main() {
    queue<Square> numOfSquares;
    Square square1("Square 1", 5);
    Square* square2 = new Square("Square 2", 8);

    numOfSquares.push(square1);
    numOfSquares.push(*square2);
    cout << "Size of queue: "<<numOfSquares.size() << endl;

    while (!numOfSquares.empty()) {
        Square square = numOfSquares.front();
        square.describe();

        numOfSquares.pop();
    }
    delete square2;
}