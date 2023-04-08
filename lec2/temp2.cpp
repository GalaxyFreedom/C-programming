#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Vector2D{
    private:
        double x, y;
    public:
        void setVector(int xAxis, int yAxis) { x = xAxis; y = yAxis; }
        double getX() { return x; }
        double getY() { return y; }

        void print() { cout << "Vector(" << x << ", " << y <<")"<<endl; }
        int distanceToOrigin(){
            double distance = sqrt(x*x + y*y);
            return sqrt(distance);}
        Vector2D add(Vector2D other){
            Vector2D sum;
            sum.x = x + other.x;
            sum.y = y + other.y;
            return sum;
        }
};

int main() {
    Vector2D vector1, vector2, vector3;
    vector1.setVector(3,7);
    vector1.print();

    vector2.setVector(2,10);
    vector2.print();

    vector3 = vector1.add(vector2);
    vector3.print();
}