#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class ScientificCalculator{

// Constants.
const double PI = 3.14159265358979323846; // Value of pi.

private:
    // Function to calculate the factorial of a number using recursion (in O(n) time and space(rescursion stack) complexity).
    long long factorial(int n){
        // Base case: factorial of 0 and 1 is 1.
        if(n == 0 || n == 1) return 1;
        
        return n * factorial(n - 1);
    }
    // Factorial can be calculated with the iterative appraoch (O(n) time complexity and O(1) space complexity) as well.
    // But we are using recursion here for the sake of demonstration.

public:
    // All the operations that can be performed by the calculator are defined in this function.
    void displayMenu(){
        cout << "Welcome to the Advanced Scientific Calculator!" << endl;
        cout << "You can perform the following operations: " << endl;
        cout << "[0] Exit Program"<< endl;
        cout << "[1] Addition (+)               [11] Sine (sin)"<< endl;
        cout << "[2] Subtraction (-)            [12] Cosine (cos)"<< endl;
        cout << "[3] Multiplication (*)         [13] Tangent (tan)"<< endl;
        cout << "[4] Division (/)               [14] Natural Logarithm (ln)"<< endl;
        cout << "[5] Exponentiation/Power (^)   [15] Base-10 Logarithm (log)"<< endl;
        cout << "[6] Square Root (sqrt)         [16] Factorial (!)"<< endl;
        cout << "[7] Cube Root (cbrt)           [17] Permutation (nPr)"<< endl;
        cout << "[8] Absolute Value (abs)       [18] Combination (nCr)"<< endl;
        cout << "[9] Modulo (%)                 [19] Memory Recall (MR)"<< endl;
        cout << "[10] Clear Memory (MC)         [20] Store Memory (MS)"<< endl;
        return;
    }

    // Function to execute the chosen operation based on user input.
    void executeChoice(int choice){
        double num1, num2, memory = 0, result;
        int n, r;

        switch(choice){
            // Two-number operations: Addition, Subtraction, Multiplication, Division and Exponentiation.
            case 1: case 2: case 3: case 4: case 5:
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "Enter the second number: ";
            cin >> num2;
            if(choice == 1) result = num1 + num2;
            else if(choice == 2) result = num1 - num2;
            else if(choice == 3) result = num1 * num2;
            else if(choice == 4){
                if(num2 == 0){
                    cout << "Error: Division by zero is not allowed." << endl;
                } else {
                    result = num1 / num2;
                }
            }
            else result = pow(num1, num2);
        
            cout << "Result: " << result << endl;
            memory = result; // Store the result in memory.
            break;

            // Single-number operations: Square Root, Cube Root and Absolute Value.
            case 6: case 7: case 8:
            cout << "Enter the number: ";
            cin >> num1;
            if(choice == 6) result = sqrt(num1);
            else if(choice == 7) result = cbrt(num1);
            else if(choice == 8) result = abs(num1);
            cout << "Result: " << result << endl;
            memory = result; // Store the result in memory.
            break;

            // Modulo operation.
            case 9:
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "Enter the second number: ";
            cin >> num2;
            if(num2 == 0){
                cout << "Error: Division by zero is not allowed." << endl;
            }else{
                result = fmod(num1, num2); // Using fmod for floating point modulo operation.
                cout << "Result: " << result << endl;
            }
            memory = result; // Store the result in memory.
            break;

            // Memory clear operation.
            case 10:
            memory = 0;
            cout << "Memory cleared." << endl;
            break;

            // Trigonometric operations: Sine, Cosine and Tangent.
            case 11: case 12: case 13:
            cout << "Enter the angle in degrees: ";
            cin >> num1;
            num1 = num1 * (PI / 180); // Convert degrees to radians.
            if(choice == 11) result = sin(num1);
            else if(choice == 12) result = cos(num1);
            else if(choice == 13){
                if(cos(num1) == 0){
                    cout << "Error: Tangent is not defined for this angle (cosine is zero)." << endl;
                    // We can also check if the modulo of the angle with 180 is 90 or -90 to check if the angle is an odd multiple of 90 degrees,
                    // which would make the tangent undefined.
                }else{
                result = tan(num1);
                }
            }
            cout << "Result: " << result << endl;
            memory = result; // Store the result in memory.
            break;

            // Logarithmic operations: Natural Logarithm, Base-10 Logarithm.
            case 14: case 15:
            cout << "Enter the number: ";
            cin >> num1;
            if(num1 <= 0){
                cout << "Error: Logarithm is not defined for non-positive numbers." << endl;
            }else{
                if(choice == 14) result = log(num1);
                else result = log10(num1);
                cout << "Result: " << result << endl;
                memory = result; // Store the result in memory.
                break;
            }

            // Factorial operations.
            case 16:
            cout << "Enter a non-negative integer: ";
            cin >> n;
            if(n < 0){
                cout << "Error: Factorial is not defined for negative numbers." << endl;
            }else{
                result = factorial(n);
                cout << "Result: " << result << endl;
                memory = result; // Store the result in memory.
                break;
            }

            // Permutation and Combination operations.
            case 17: case 18:
            cout << "Enter n (non-negative integer): ";
            cin >> n;
            cout << "Enter r (non-negative integer): ";
            cin >> r;
            if(n < 0 || r < 0 || r > n){
                cout << "Error: Invalid values for n and r." << endl;
            }else{
                if(choice == 17) result = (factorial(n) / factorial(n - r)); // formula for permutation nPr = (n! / (n - r)!).
                else result = (factorial(n) / (factorial(r) * factorial(n - r))); // formula for combination nCr = (n! / (r! * (n - r)!)).
                cout << "Result: " << result << endl;
                memory = result; // Store the result in memory.
                break;
            }

            // Memory recall operation.
            case 19:
            cout << "Memory Recall: " << memory << endl;
            break;

            // Memory store operation.
            case 20:
            cout << "Enter the value to store in memory: ";
            cin >> memory;
            cout << "Value has been stored in the memory." << endl;
            break;
            
            // Default case for invalid choice.
            default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    };
};

int main(){
    cout << setprecision(10); // Set the precision for floating point output to 10 significant digits.
    ScientificCalculator calc;
    int choice;
    do{
        calc.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        calc.executeChoice(choice);
    }while(choice != 0);
    cout << "Thank you for using the Advanced Scientific Calculator.\nGoodbye!" << endl;
    return 0;
}
