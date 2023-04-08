#include <iostream>
#include <string>

using namespace std;

class Math1{
private:
public:
    Math1(){}
    ~Math1(){}
    bool isEven(int x){
        if(x%2==0) { return true; }
        else { return false; }
    }
    int factorial(int x) {
        int result = 1;
        for(int i=1; i<=x; i++) { result *= i; }
    return result;
    }
};
class Math2{
private:
public:
    Math2(){}
    ~Math2(){}
    bool isEven(int x) {
        if (x%2==0) { return true; }
        else { return false; }
    }
    int factorial(int x) {
        int result = 1;
        for(int i=1 ; i<=x; i++) { result *= i; }
        return result;
    }
    double estimateE(int x) {
        double result = 0;
        for(int i=0; i<=x; i++) { result += 1.0/factorial(i); }
        return result;
    }
};

int main() {
    Math1 math1;
    Math2 math2;
    cout << "5 is even: " << (bool)math1.isEven(5) << endl;
    cout << "6 is even: " << (bool)math2.isEven(6) << endl;

    cout << "Factorial of 5 is " << math1.factorial(5) << endl;
    cout << "Factorial of 6 is " << math2.factorial(6) << endl;

    cout << "Estimate e with n=5: " << math2.estimateE(5) << endl;
    cout << "Estimate e with n=6: " << math2.estimateE(6) << endl;
}
