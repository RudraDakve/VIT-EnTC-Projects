#include <iostream>
#include <cmath>
#using namespace std;

int main(){
    double voltage, current, resistance;
    int choice;
    cout << "Welcome to C++ Resistance Measurement Simulator!" << endl;
    cout << "You can calculate the resistance using Ohm's Law: R = V / I" << endl;
    cout << "Enter the voltage applied across the resistor (in volts): " << endl;
    cin >> voltage;
    cout << "Enter the current flowing through the resistor (in amperes): " << endl;
    cin >> current;
    if(current == 0){
        cout << "Error! : Current cannot be zero! (leading to infinite resistance)" << endl;
        return 0;
    }
    if(voltage == 0){
        cout << "Error! : Voltage cannot be zero! (leading to no flow of current, meaning no resistance)" <<endl;
        return 0;
    }
    resistance = voltage / current;
    if(resistance < 0){
        cout << "The resistance of the resistor is: " << -(resistance) << "ohms" << endl;
        cout << "Since resistance cannot be negative, please check the direction of current and voltage applied." << endl;
        return 0;
    }
    if(resistance >= 1000000){
        cout << "The resistance of the resistor is: " << resistance/1000000 << "mega-ohms" << endl;
        return 0;
    }else if(resistance >= 1000 && resistance < 1000000){
        cout << "The resistance of the resistor is: " << resistance/1000 << "kilo-ohms" << endl;
        return 0; 
    }else{
       cout << "The resistance of the resistor is: " << resistance << "ohms" << endl;
        return 0;
    }
};
