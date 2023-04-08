#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << endl;
    }

    return 0;
}