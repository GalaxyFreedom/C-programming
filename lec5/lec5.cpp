#include <iostream>
#include <string>

using namespace std;

class Vector {
    private:
        int x,y ;
    public:
        Vector() : x(0), y(0) {}
        ~Vector() {}
        Vector(int x, int y) : x(x), y(y) {}
        void add(const Vector& vector) { x+= vector.x; y+= vector.y; }
        int dotProduct(const Vector& vector) { return x*vector.x + y*vector.y; }
        bool check(const Vector& vector) { return x==vector.x && y==vector.y; }
        void print() { cout << "Vector{" << x << "," << y << "}" << endl; }
};

int main() {
    Vector x{ 2,3 }, y{ 4,2 }, u{ 4,4 }, v{ 3,3 };
    x.add(u);
    y.add(v);
    x.print();
    y.print();

    int dot = x.dotProduct(y);
    cout <<"Dot Product: "<< dot << endl;

    bool check = x.check(y);
    if (check != true )
        cout << "Two vectors are not equal." << endl;
    else
        cout << "Two vectors are equal." << endl;
}