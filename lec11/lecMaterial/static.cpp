#include <iostream>
using namespace std;

class Square {
public:
    static int objectCount;
    // constructor
    Square() { objectCount++; }
    static int getObjectCount() { return objectCount; }
};

int Square::objectCount = 0;

int main() {
    Square square1;
    Square square2;
    cout << square1.objectCount << endl;
    cout << square2.objectCount << endl;
    cout << Square::objectCount << endl;

    cout << square1.getObjectCount() << endl;
    cout << square2.getObjectCount() << endl;
    cout << Square::getObjectCount() << endl;
    return 0;
}
