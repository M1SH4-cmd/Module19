#include <iostream>
#include <fstream>
#include <vector>

int main(){
    std::vector<double> purse;
    std::ifstream bank;
    bank.open("C:\\Users\\OG MICHAEL\\Desktop\\Module19\\bank.txt");
    //bank.read(buffer, sizeof(buffer));

    double sum = 0;

    while(!bank.eof()){
        double money;
        bank >> money;
        purse.push_back(money);
    }

    for(int i = 0; i < purse.size(); ++i){
        sum += purse[i];
    }

    std::cout << "Sum: " << sum;

    //std::cout << buffer << std::endl;
    bank.close();
}