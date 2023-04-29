#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T> void sumComputation(T& sum, T x, int n) {
    sum = 1;
    for (int i = 1; i <= n; i++) {
        sum += pow(x, i)/i;
    }
}

int main() {
    double sum;
    sumComputation(sum, 2.0, 4);
    cout << sum << endl;
    return 0;
}