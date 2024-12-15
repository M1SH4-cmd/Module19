#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream words;
    words.open("..\\words.txt");

    cout << "Enter your word to find:" << endl;
    string wordToFind;
    cin >> wordToFind;

    for(char& c : wordToFind){
        c = tolower(c);
    }

    int count = 0;

    while(!words.eof()){
        string word;
        words >> word;
        if(word == wordToFind) count++;
    }
    cout << count << endl;

    words.close();
    return 0;
}
