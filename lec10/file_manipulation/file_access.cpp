#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // create a file to write if it doesn't exist
    // or write to it if it exists
    ofstream outputStream;

    // file name
    outputStream.open("data.txt");

    if (outputStream.is_open()) {
        // write data
        string line1 = "C++ Programming.\n";
        outputStream << line1;

        string line2 = "VGU 2022.\n";
        outputStream << line2;

        // close file
        outputStream.close();
    }
    else {
        cout << "Unable to open file. " << endl;
    }

    // create a string to read from the file to that string
    string line;
    // chose file name to read from
    ifstream inputStream("data.txt");

    if (inputStream.is_open()) {
        while (getline(inputStream, line)) {
            cout << line << endl;
        }
        inputStream.close();
    }
    else {
        cout << "Unable to open file. " << endl;
    }
}