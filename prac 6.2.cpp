#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> history;

    string page;
    int choice;

    cout << "1. Visit page\n";
    cout << "2. Back\n";
    cout << "3. Exit\n";

    while (true) {
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter page: ";
            cin >> page;

            history.push(page);

            cout << "Current page: " << history.top() << endl;
        }

        else if (choice == 2) {

            if (history.size() <= 1) {
                cout << "No previous page!\n";
            } else {
                history.pop();
                cout << "Current page: " << history.top() << endl;
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
