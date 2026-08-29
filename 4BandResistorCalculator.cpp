#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

struct BandData{
    int digit;
    double multiplier;
};
int main(){
    unordered_map<string, BandData> colourMap = {
        {"black", {0, 1}},
        {"brown", {1, 10}},
        {"red", {2, 100}},
        {"orange", {3, 1000}},
        {"yellow", {4, 10000}},
        {"green", {5, 100000}},
        {"blue", {6, 1000000}},
        {"violet", {7, 10000000}},
        {"grey", {8, 100000000}},
        {"white", {9, 1000000000}},
        {"gold", {-1, 0.1}},
        {"silver", {-1, 0.01}}
    };
    unordered_map<string, double> toleranceMap = {
        {"brown", 0.01},
        {"red", 0.02},
        {"green", 0.005},
        {"blue", 0.0025},
        {"violet", 0.001},
        {"grey", 0.0005},
        {"gold", 0.05},
        {"silver", 0.10},
        {"none", 0.20}
    };
    string b1, b2, b3, b4;
    cout << "Welcome to the 4-Band Resistor Calculator!" << endl;
    cout << "Enter the colour of 1st band colour (eg. red): ";
    cin >> b1;
    cout << "Enter the colour of 2nd band colour (eg. blue): ";
    cin >> b2;
    cout << "Enter the colour of 3rd band (Multiplier) colour: ";
    cin >> b3;
    cout << "Enter the colour of 4th band (Tolerance) colour: ";
    cin >> b4;
    if(colourMap.find(b1) == colourMap.end() || colourMap.find(b2) == colourMap.end() || colourMap.find(b3) == colourMap.end() || colourMap.find(b4) == colourMap.end()){
        cout << "Invalid colour input. Please check the colours and try again." << endl;
        return 1;
    }
    int digit1 = colourMap[b1].digit;
    int digit2 = colourMap[b2].digit;
    double multiplier = colourMap[b3].multiplier;
    double tolerance = toleranceMap[b4];
    if(digit1 == -1 || digit2 == -1){
        cout << "Invalid, gold and silver cannot be used for the first two bands." << endl;
        return 1;
    }
    double resistance = ((digit1 * 10) + digit2) * multiplier;
    cout << "The calculated resistance is: ";
    if(resistance >= 1000000){
        cout << resistance / 1000000 << "Mega ohms" << endl;
    }else if(resistance >= 1000){
        cout << resistance / 1000 << "Kilo ohms" << endl;
    }else{
        cout << resistance << "ohms" << endl;
    }
    return 0;
};