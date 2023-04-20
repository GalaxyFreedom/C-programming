#include <iostream>
using namespace std;

int main() {
    int* ptr = NULL;
    const int size = 5;
    ptr = new int[size];
    for (int i = 0; i < size; i++) {
        ptr[i] = i*i;
    }
    for (int i = 0; i < size; i++) {
        cout << "Value at index "<< i << endl;
        cout << " is " << ptr[i] << endl;
    }
    delete[] ptr;
}