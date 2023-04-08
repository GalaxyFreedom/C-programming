#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Shape {
    public:
        virtual void describe()=0;
        virtual double area()=0;
};

class Rectangle: public Shape {
    private:
        int length;
        int width;
    public:
        Rectangle(int length, int width){
            this->length = length;
            this->width = width;
        }
        void describe(){
            cout << "length: " << length
                 << " - width: " << width
                 << " - Area:" << area() << endl;
        }
        double area() {
            return length*width;
        }
};

class Square: public Shape{
    private:
        int side;
    public:
        Square(int side){
            this->side = side;
        }
        void describe(){
            cout << "side: " << side
            << " - Area:" << area() << endl;
        }
        double area() {
            return side*side;
        }
};

bool compare(Shape* shape1, Shape*shape2){
    return (shape1->area()) < (shape2->area()) ;
};

class Canvas {
    private:
        vector<Shape*> listOfShapes;
    public:
        void addShape(Shape *shape){
            listOfShapes.push_back(shape);
        }

        void describe(){
            for(int i=0; i<listOfShapes.size(); i++){
                listOfShapes[i]->describe();
            }
        }

        void sortByArea(){
            sort(listOfShapes.begin(), listOfShapes.end(), compare);
        }

        int countNumOfSquares() {
            int result = 0;
            for(int i=0; i<listOfShapes.size(); i++){
                if (Square* sh = dynamic_cast<Square*>(listOfShapes[i])) {
                    result++;
                }
            }
            return result;
        }

        double computeRectangleArea() {
            double result = 0;
            for(int i=0; i<listOfShapes.size(); i++){
                if (Rectangle* sh = dynamic_cast<Rectangle*>(listOfShapes[i])) {
                    result = result + sh->area();
                }
            }
            return result;
        }
};

int main () {
   Rectangle rec1(3, 7);
   Rectangle rec2(2, 4);
   Square square(5);

   Canvas canvas;
   canvas.addShape(&rec1);
   canvas.addShape(&rec2);
   canvas.addShape(&square);

   // describe
   canvas.describe();
   cout << "------------" << endl;

   // sort
   canvas.sortByArea();
   canvas.describe();

   // count
   cout << "------------" << endl;
   int numOfSquares = canvas.countNumOfSquares();
   cout << "numOfSquares: " << numOfSquares << endl;

   // total area
   cout << "------------" << endl;
   double totalArea = canvas.computeRectangleArea();
   cout << "totalArea: " << totalArea << endl;

   return 0;
}