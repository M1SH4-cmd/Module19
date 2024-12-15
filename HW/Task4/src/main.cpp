#include <iostream>
#include <fstream>
using namespace std;
int main(){
    char pattern[7] = {'-', '1', '1', '9', 'P', 'N', 'G'};
    string path = "OG.png";
    // cout << "Enter the path of the file: ";
    // cin >> path;


    ifstream file;
    file.open(path, ios::binary);
    if (!file.is_open()){
        cout << "Invalid file path!";
        return 1;
    }

    if(path.substr(path.length() - 4, 3) != "png"){
        cout << "This is not a .png file" << endl;
        return 0;
    }
    char binaryCode[7];
    file.read(binaryCode, 7);

    if(binaryCode == pattern) cout << "This is a .png file" << endl;
    else cout << "This is not a.png file" << endl;

    file.close();
    return 0;
}