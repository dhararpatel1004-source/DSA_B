#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter stack size: ";
    cin >> n;

    int stack[100];
    int top = -1;

    int choice, value;

    cout << "\n1. Place (Push)\n";
    cout << "2. Take (Pop)\n";
    cout << "3. Exit\n";

    while (true) {
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter tray number: ";
            cin >> value;


            if (top == n - 1) {
                cout << "Error: Stack is full!\n";
            } else {
                top++;
                stack[top] = value;
                cout << "Top tray: " << stack[top] << endl;
            }
        }

        else if (choice == 2) {

            if (top == -1) {
                cout << "Error: Stack is empty!\n";
            } else {
                cout << "Taken tray: " << stack[top] << endl;
                top--;

                if (top == -1)
                    cout << "Stack is empty\n";
                else
                    cout << "Top tray: " << stack[top] << endl;
            }
        }

        else if (choice == 3) {
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

