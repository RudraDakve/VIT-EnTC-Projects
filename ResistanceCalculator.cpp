#include <iostream>
#include <iomanip>
using namespace std;

double calculateSeriesResistance(int n){
    double totalR = 0.0;
    double currentR = 0.0;
    cout << "Enter the value of each resistor in ohms: ";
    for(int i = 1; i <= n; i++){
        cout << "Resistor R" << i << ": ";
        cin >> currentR;
        totalR += currentR;
    }
    return totalR;
}
double calculateParallelResistance(int n){
    double inverseSum = 0.0;
    double currentR = 0.0;
    cout << "Enter the value of each resistor in ohms: ";
    for(int i = 1; i <= n; i++){
        cout << "Resistor R" << i << ": ";
        cin >> currentR;
        inverseSum += 1.0 / currentR;
    }
    return 1.0 / inverseSum;
}
int main(){
    int choice, numResistors;
    cout <<  fixed << setprecision(3);
    cout << "Welcome to the Resistance Calculator!" << endl;
    cout << "Choose the type of connection you have used for the resistors: " << endl;
    cout << "1. Series Combination" << endl;
    cout << "2. Parallel Combination" << endl;
    cin >> choice;
    if(choice != 1 && choice != 2){
        cout << "Invalid choice! Please enter 1 or 2 for Series or Parallel combination respectively." << endl;
        return 1;
    }
    cout << "Enter the number of resistors: ";
    cin >> numResistors;
    if(numResistors <= 0){
        cout << "Invalid number of resistors! Number of resistors should be greater than 0." << endl;
        return 1;
    }
    double totalResistance;
    switch(choice){
        case 1:
            totalResistance = calculateSeriesResistance(numResistors);
            cout << "The Equivalent Resistance of the Series combination is: " << totalResistance << endl;
            break;
        case 2:
            totalResistance = calculateParallelResistance(numResistors);
            cout << "The Equivalent Resistance of the Parallel combination is: " << totalResistance << endl;
            break;
    }
    return 0;
};