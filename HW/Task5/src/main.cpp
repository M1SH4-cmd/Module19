#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int TOTAL_SECTORS = 13;
const int WINNING_SCORE = 6;

int main(){
    vector<string> questions(TOTAL_SECTORS);
    vector<string> answers(TOTAL_SECTORS);
    vector<bool> played(TOTAL_SECTORS, false);
    int playerScore = 0;
    int viewerScore = 0;
    int currentSector = 0;

    ifstream questionsFile("..\\questions.txt");
    if(!questionsFile){
        cout << "Issue occured while opening file." << endl;
        return 1;
    }
    for(int i = 0; i < TOTAL_SECTORS; ++i){
        getline(questionsFile, questions[i]);
    }
    questionsFile.close();

    ifstream answersFile("..\\answers.txt");
    if(!answersFile){
        cout << "Issue occured while opening file." << endl;
        return 1;
    }
    for(int i = 0; i < TOTAL_SECTORS; ++i){
        getline(answersFile, answers[i]);
    }
    answersFile.close();

    while(playerScore < WINNING_SCORE && viewerScore < WINNING_SCORE){
        int offset;
        cout << "Qurrent sector: " << (currentSector + 1) << endl;
        cout << "Enter the offset: ";
        cin >> offset;

        currentSector = (currentSector + offset) % TOTAL_SECTORS;
        if(currentSector < 0){
            currentSector += TOTAL_SECTORS;
        }

        while(played[currentSector]){
            currentSector = (currentSector + 1) % TOTAL_SECTORS;
        }

        played[currentSector] = true;

        cout << "Question: " << questions[currentSector] << endl;

        string playerAnswer;
        cout << "Your answer: ";
        cin >> playerAnswer;

        if(playerAnswer == answers[currentSector]){
            cout << "Correct answer! You gain 1 point." << endl;
            playerScore++;
        }else{
            cout << "Incorrect answer! Viewer gain 1 point." << endl;
            viewerScore++;
        }

        cout << "Board: Player - " << playerScore << ", Viewer - " << viewerScore << endl;
    }

    if(playerScore >= WINNING_SCORE){
        cout << "Cangratulations! You win!" << endl;
    } else {
        cout << "Viewer win!" << endl;
    }

    return 0;
}