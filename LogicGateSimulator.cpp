#include <iostream>
using namespace std;

int main(){
    int input1, input2;
    int choice;
    int result;
    cout << "Welcome to C++ Logic Gate Simulator!" << endl;
    cout << "You can perform any operation on the following logic gates: AND, OR and XOR" <<endl;
    cout << "Enter any two Binary numbers (0 or 1) to perform the operation: " << endl;
    cin >> input1 >> input2;
    cout << "Enter the operation you want to perform
    1 - for AND
    2 - for OR
    3 - for XOR" << endl;
    cin >> choice;
    if((input1 != 0 && input1 != 1) && (input2 != 0 && input2 != 1)){
        cout << "Error! : Invalid inputs entered!" << endl;
        return 0;
    }
    switch(choice){
        case 1:
            result = input1 && input2;
            cout << "Result of AND operation: " << result << endl;
            break;
        case 2:
        result = input1 || input2;
            cout << "Result of OR operation: " << result << endl;
            break;
        case 3:
            result = input1 ^ input2;
            cout << "Result of XOR operation: " << result << endl;
            break;
        default:
            cout << "Error! : Invalid choice entered!" << endl;
    }
    return 0;
};
