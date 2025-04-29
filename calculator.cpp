#include <bits/stdc++.h>
using namespace std;

void simplecalculator() {
    cout << "\n===== SIMPLE CALCULATOR =====" << endl;
    cout << "Choose operation:" << endl;
    cout << "+  : Addition" << endl;
    cout << "-  : Subtraction" << endl;
    cout << "*  : Multiplication" << endl;
    cout << "/  : Division" << endl;
    cout << "%  : Modulus (Integers only)" << endl;
    cout << "^  : Power" << endl;
    cout << "s  : Square Root" << endl;
    cout << "=============================\n";
}

int main() {
    char op, choice;
    double num1, num2, result;

    do {
        simplecalculator();
        cout << "Enter operator: ";
        cin >> op;

        if (op == 's' || op == 'S') {
            cout << "Enter a number: ";
            cin >> num1;
            if (num1 >= 0) {
                result = sqrt(num1);
                cout << "√" << num1 << " = " << result << endl;
            } else {
                cout << "Error: Cannot take square root of a negative number!" << endl;
                result = NAN;
            }
            ofstream logFile("log.txt", ios::app);
            if (logFile.is_open()) {
                logFile << "sqrt(" << num1 << ") = " << result << endl;
                logFile.close();
            }
        } else {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;

            switch (op) {
                case '+':
                    result = num1 + num2;
                    cout << "Result: " << result << endl;
                    break;
                case '-':
                    result = num1 - num2;
                    cout << "Result: " << result << endl;
                    break;
                case '*':
                    result = num1 * num2;
                    cout << "Result: " << result << endl;
                    break;
                case '/':
                    if (num2 != 0) {
                        result = num1 / num2;
                        cout << "Result: " << result << endl;
                    } else {
                        cout << "Error: Division by zero!" << endl;
                        result = NAN;
                    }
                    break;
                case '%':
                    if ((int)num2 != 0) {
                        result = (int)num1 % (int)num2;
                        cout << "Result: " << result << endl;
                    } else {
                        cout << "Error: Modulus by zero!" << endl;
                        result = NAN;
                    }
                    break;
                case '^':
                    result = pow(num1, num2);
                    cout << "Result: " << result << endl;
                    break;
                default:
                    cout << "Invalid operator!" << endl;
                    result = NAN;
            }
            ofstream logFile("log.txt", ios::app);
            if (logFile.is_open()) {
                logFile << num1 << " " << op << " " << num2 << " = " << result << endl;
                logFile.close();
            }
        }

        cout << "\nDo you want to perform another operation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the calculator!" << endl;
    return 0;
}
