#include <iostream>
#include <string>

using namespace std;

class Vector {
    private:
        int x,y;
    public:
        Vector() : x(1), y(1) {}
        ~Vector() {}
        Vector(int x, int y) : x(x), y(y) {}
        void add(Vector vector) { this->x += vector.x; this->y += vector.y; }
        int dot(Vector vector) { int res = 0; res = this->x * vector.x + this-> y * vector.y; return res; }
        bool check(Vector vector) {
            if ( this->x == vector.x && this->y == vector.y )
                return true;
            else
                return false;
        }
        void print() { cout << "Vector{" << this->x << ", " << this->y << "}" << endl;}
};

int main() {
    Vector x{ 1,2 }, y{ 4,2 }, u{ 4,4 }, v{ 3,3 };
    x.add(u);
    y.add(v);

    x.print();
    y.print();

    int res = x.dot(y);
    cout << "Dot product: " << res << endl;

    bool check = x.check(y);
    if ( check == true )
        cout << "Two vectors are equal. " << endl;
    else
        cout << "Two vectors are not equal. " << endl;
}