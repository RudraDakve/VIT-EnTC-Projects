#include <iostream>
#include <bits\stdc++.h>
using namespace std;

int main(){
    double num1, num2;
    char op;
    char choise;
    do{
        cout<< "\nEnter first number: ";
        cin>> num1;
        cout<<"Enter an operator (+, -, *, /): ";
        cin>> op;
        cout<<"Enter second number: ";
        cin>>num2;
        switch(op){
            case '+':
            cout<< "Result:" << num1 + num2 << endl;
            break;
            case '-':
            cout<< "Result:" << num1 - num2 << endl;
            break;
            case '*':
            cout<< "Result:" << num1 * num2 << endl;
            break;
            case '/':
            if(num2 == 0){
                cout<< "Error! Division by 0 is Mathematically undefined." << endl;
            }else{
                cout<< "Result:" << num1 - num2 << endl;
            }
            break;
            default:
            cout << "Invalid operator entered!" << endl;
            break;
        }
        cout << "\nDo you want to any other calculation? (y/n)";
        cin>> choise;
    }while(choise == 'y' || choise == 'Y');
    cout << "Thank you for using the calculator!" <<endl;
    return 0;
}