#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    int sum = 0;
    int maxPayment = 0;
    string monthEmployee;

    ifstream employeesList;
    employeesList.open("list.txt");

    vector<string> buffer;

    while(!employeesList.eof()){
        string employee;
        getline(employeesList, employee, '\n');
        buffer.push_back(employee);
    }

    for(int i = 0; i < buffer.size(); ++i){
        istringstream iss(buffer[i]);
        string name;
        string scndName;
        int payment;
        iss >> name >> scndName >> payment;
        sum += payment;
        if(payment > maxPayment){
            maxPayment = payment;
            monthEmployee = name + " " + scndName;
        }
    }


    cout << "Sum of all payments:\t" << sum << endl;
    cout << "Biggest payment worker:\t" << monthEmployee << endl;

    employeesList.close();
    return 0;
}