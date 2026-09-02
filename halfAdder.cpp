# include <iostream>
using namespace std;

bool AND_gate(bool a, bool b){
    return a && b;
};
bool OR_gate(bool a, bool b){
    return a || b;
};
bool XOR_gate(bool a, bool b){
    return a != b;
};

void halfAdder(){
    bool A, B;
    cout << " Welcome to the Half Adder Simulator" << endl;
    cout << "Enter the first input (0 or 1): ";
    cin >> A;
    cout <<"Enter the second input (0 or 1): ";
    cin >> B;

    bool sum = XOR_gate(A, B);
    bool carry = AND_gate(A, B);
    cout << "Sum (A XOR B): " << sum << endl;
    cout << "Carry (A AND B): " << carry << endl;
    return;
};

void fullAdder(){
    bool A, B, Cin;
    cout << "Welcome to the Full Adder Simulator" << endl;
    cout << "Enter the first input (0 or 1): ";
    cin >> A;
    cout << "Enter the second input (0 or 1): ";
    cin >> B;
    cout << "Enter the Carry input (0 or 1): ";
    cin >> Cin;

    bool sum1 = XOR_gate(A, B);
    bool carry1 = AND_gate(A, B);
    bool sum = XOR_gate(sum1, Cin);
    bool carry2 = AND_gate(sum1, Cin);
    bool Cout = OR_gate(carry1, carry2);
    cout << "Sum (A XOR B XOR Cin): " << sum << endl;
    cout << "Carry (Cout): " << Cout << endl;
};

int main(){
    cout << "Welcome to the Adder Simulator!" << endl;
    cout << "Choose the type of adder you want to use: " << endl;
    cout << "1. Half Adder" << endl;
    cout << "2. Full Adder" << endl;
    cout << "3. Exit" << endl;
    int choice;
    cin >> choice;
    do{
    switch(choice){
        case 1:
            halfAdder();
            break;
        case 2:
            fullAdder();
            break;
        case 3:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice! Please enter 1 or 2 for Half Adder or Full Adder respectively." << endl;
            break;
    }while(choice != 3);
    return 0;
};
