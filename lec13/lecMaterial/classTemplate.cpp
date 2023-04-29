#include <iostream>
using namespace std;

template<typename T> class Array {
private:
    T* m_ptr;
    int m_size;
public:
    Array(T arr[], int size) : m_ptr(new T[size]), m_size(size) {
        for (int i = 0; i < size; i++) {
            m_ptr[i] = arr[i];
        }
    }

    void print() {
        for (int i = 0; i < m_size; i++) {
            cout << " " << *(m_ptr + i);
        }
        cout << endl;
    }
};

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    Array<int> a(arr, 5);
    a.print();
    return 0;
}