//Task:Digital calculator
#include <iostream>
using namespace std;

int main() {
    int choice;
    double a, b;

    cout << "1.Add 2.Sub 3.Mul 4.Div\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice < 1 || choice > 4) {
        cout << "Invalid choice";
        return 0;
    }

    cout << "Enter two numbers: ";
    cin >> a >> b;

    if (choice == 1)
        cout << "Result = " << a + b;
    else if (choice == 2)
        cout << "Result = " << a - b;
    else if (choice == 3)
        cout << "Result = " << a * b;
    else if (choice == 4) {
        if (b == 0) 
            cout << "Error! Division by zero";
        else
            cout << "Result = " << a / b;
    }

    return 0;
}
