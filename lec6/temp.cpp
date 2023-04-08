#include <iostream>
#include <string>

using namespace std;

class Math1 {
public:
    bool isEvenNumber(int number) {
        bool result = false;
        if (number%2 == 0) { result = true; }
        return result;
    }
    int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++) { result *= i; }
        return result;
    }
};
class Math2 : public Math1 {
public:
    double estimateEulerNumber(int numLoops) {
        double result = 1.0;
        for (int i = 1; i <= numLoops; i++) { result += 1.0/factorial(i); }
        return result;
    }
};
int main() {
    Math2 m2;
    cout << "Factorial of 4 is " << m2.factorial(4) << endl;
    cout << "isEvenNumber(4) is " << m2.isEvenNumber(4) << endl;
    cout << "Estimate Euler number is " << m2.estimateEulerNumber(16) << endl;
    return 0;
}