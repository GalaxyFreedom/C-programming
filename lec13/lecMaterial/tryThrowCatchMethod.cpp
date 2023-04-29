#include <iostream>
#include <string>
using namespace std;

class Cat {
private:
    string m_name;
    float m_weight;
public:
    Cat(string name, float weight) : m_name(name) {
        try {
            if (weight > 0) {
                m_weight = weight;
            }
            else {
                throw(weight);
            }
        }
        catch (float inputNum) {
            cout << "Input number is " << inputNum << endl;
            cout << "THe program is stopped." << endl;
            exit(1);
        }
    }

    void describe() {
        cout << "I amm " << m_name << ", and "<<endl;
        cout << "my weight is " << m_weight << endl;
    }
};

int main() {
    Cat calico("Calico", 4.2);
    calico.describe();

    return 0;
}