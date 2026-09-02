# include <iostream>
using namespace std;

bool AND_gate(bool a, bool b){
    return a && b;
};
bool XOR_gate(bool a, bool b){
    return a != b;
};

void halfAdder(){
    bool a, b;
    cout << "Enter the first input (0 or 1): ";
    cin >> a;
    cout <<"Enter the second input (0 or 1): ";
    cin >> b;
    bool sum = XOR_gate(a, b);
    bool carry = AND_gate(a, b);
    cout << "Sum (A XOR B): " << sum << endl;
    cout << "Carry (A AND B): " << carry << endl;
    return;
};

int main(){
    int choice = 1;
    do{
    cout << "Welcome to the Half Adder Simulator" << endl;
    cout << "Enter the choice for the required operation" << endl;
    cout << "1. Half Adder." << endl;
    cout << " 2. Exit from the program.";
    cin >> choice;
    }while(choice == 1);
    return 0;
};
