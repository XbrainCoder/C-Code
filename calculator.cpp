//write a c++ program for Calculator for Scientific Operations


#include <iostream>
#include <cmath>
using namespace std;

void showMenu() {
    cout << "********** Scientific Calculator **********" << endl;
    cout << "Select operation:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Sine (sin)" << endl;
    cout << "6. Cosine (cos)" << endl;
    cout << "7. Tangent (tan)" << endl;
    cout << "8. Exponential (exp)" << endl;
    cout << "9. Logarithm (log)" << endl;
    cout << "10. Power (^)" << endl;
    cout << "11. Square root (sqrt)" << endl;
    cout << "0. Exit" << endl;
    cout << "*******************************************" << endl;
}






int main() {
    int choice;
    double num1, num2;

    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 + num2 << endl;
                break;
            case 2:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 - num2 << endl;
                break;
            case 3:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 * num2 << endl;
                break;
            case 4:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                if (num2 != 0) {
                    cout << "Result: " << num1 / num2 << endl;
                } else {
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            case 5:
                cout << "Enter an angle in radians: ";
                cin >> num1;
                cout << "Result: " << sin(num1) << endl;
                break;
            case 6:
                cout << "Enter an angle in radians: ";
                cin >> num1;
                cout << "Result: " << cos(num1) << endl;
                break;
            case 7:
                cout << "Enter an angle in radians: ";
                cin >> num1;
                cout << "Result: " << tan(num1) << endl;
                break;
            case 8:
                cout << "Enter a number: ";
                cin >> num1;
                cout << "Result: " << exp(num1) << endl;
                break;
            case 9:
                cout << "Enter a number: ";
                cin >> num1;
                if (num1 > 0) {
                    cout << "Result: " << log(num1) << endl;
                } else {
                    cout << "Error: Logarithm of non-positive number!" << endl;
                }
                break;
            case 10:
                cout << "Enter base and exponent: ";
                cin >> num1 >> num2;
                cout << "Result: " << pow(num1, num2) << endl;
                break;
            case 11:
                cout << "Enter a number: ";
                cin >> num1;
                if (num1 >= 0) {
                    cout << "Result: " << sqrt(num1) << endl;
                } else {
                    cout << "Error: Square root of negative number!" << endl;
                }
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while(choice != 0);

    return 0;
}