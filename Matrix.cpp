#include <iostream>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<double>>& matrix){
    for(int i = 0; i < 3; i++){
        cout << "[ ";
        for(int j = 0; j < 3; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "]" << endl;
    }
};

void inputMatrix(vector<vector<double>>&matrix, char name){
    cout <<"Enter elements for matrix " << name << " (3x3 row by row): " << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << name << "[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> matrix[i][j];
        }
    }
};

void addMatrix(){
    vector<vector<double>> A(3, vector<double>(3));
    vector<vector<double>> B(3, vector<double>(3));
    vector<vector<double>> C(3, vector<double>(3), 0.0);

    inputMatrix(A, 'A');
    inputMatrix(B, 'B');

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    cout << "Result of addition: " << endl;
    printMatrix(C);
};

void subtractMatrix(){
    vector<vector<double>> A(3, vector<double>(3));
    vector<vector<double>> B(3, vector<double>(3));
    vector<vector<double>> C(3, vector<double>(3), 0.0);

    inputMatrix(A, 'A');
    inputMatrix(B, 'B');

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    cout << "Result of subtraction: " << endl;
    printMatrix(C);
};

void multiplyMatrix(){
    vector<vector<double>> A(3, vector<double>(3));
    vector<vector<double>> B(3, vector<double>(3));
    vector<vector<double>> C(3, vector<double>(3), 0.0);

    inputMatrix(A, 'A');
    inputMatrix(B, 'B');

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "Result of multiplication: " << endl;
    printMatrix(C);
};

void calculateDeterminant(){
    vector<vector<double>> A(3, vector<double>(3));
    inputMatrix(A, 'A');
    double determinant = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) -
                         A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
                         A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
    cout << "Determinant of matrix A: " << determinant << endl;
};

int main(){
    int choice;
    do{
        cout << "Matrix Calculator" << endl;
        cout << "1.Add two 3x3 matrices" << endl;
        cout << "2.Subtract two 3x3 matrices" << endl;
        cout << "3.Multiply two 3x3 matrices" << endl;
        cout << "4.Calculate determinant of a 3x3 matrix" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                addMatrix();
                break;
            case 2:
                subtractMatrix();
                break;
            case 3:
                multiplyMatrix();
                break;
            case 4:
                calculateDeterminant();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }while(choice != 5);
    return 0;
};