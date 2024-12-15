#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string file_path;
    cout << "Enter the path to the file: ";
    getline(cin, file_path);
    

    ifstream file(file_path, ios::binary);
    
    if (!file) {
        cout << "Invalid file path!" << endl;
        return 1;
    }

    char header[8];
    file.read(header, 8);

    // Проверяем, что заголовок соответствует PNG
    if (header[0] == -119 && 
        header[1] == 'P' && 
        header[2] == 'N' && 
        header[3] == 'G') {
        cout << "This is a png file" << endl;
    } else {
        cout << "This is not a png file" << endl;
    }

    return 0;
}