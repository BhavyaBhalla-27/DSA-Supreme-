// In the cases of switch statement, char expression should be in single quotes, so corrected for all the cases and also break statement is to be used after every case ends 
// Also instead of /, * should come and instead of *, / should come. Corrected this also
#include <iostream>
using namespace std;
int main() {
    char oper;
    float num1, num2;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> oper;
    cout << "Enter two numbers: " << endl;
    cin >> num1 >> num2;
    switch (oper) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;break;
        case '/':
            cout << num1 << " / " << num2 << " = " << num1 / num2;break;
        default:
            // operator is doesn't match any case constant (+, -, *, /)
            cout << "Error! The operator is not correct";
            break;
    }

    return 0;
}