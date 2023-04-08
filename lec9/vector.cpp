#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers { 0, 1, 2 };

    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << " " << numbers[i];
    }
    cout << endl << "--------------------------------" << endl;

    numbers.push_back(3);
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << " " << numbers[i];
    }
    cout << endl << "--------------------------------" << endl;


    numbers.erase(numbers.begin()+2);
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << " " << numbers[i];
    }
    cout << endl << "--------------------------------" << endl;

    numbers.insert(numbers.begin()+2, 9);
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << " " << numbers[i];
    }
    cout << endl << "--------------------------------" << endl;

}