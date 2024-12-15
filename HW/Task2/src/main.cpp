#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    cout << "Enter a path to the file:" << endl;
    string filePath;
    getline(cin, filePath);

    ifstream file;
    file.open(filePath);

    if (!file.is_open()) {
        cout << "Error occured while opening the file!"<< endl;
        return 1;
    }

    vector<string> buffer;

    while(!file.eof()){
        string value;
        getline(file, value, '\n');
        buffer.push_back(value);
    }

    for(int i = 0; i < buffer.size(); ++i){
        cout << buffer[i] << "\n";
    }

    file.close();
    return 0;
}