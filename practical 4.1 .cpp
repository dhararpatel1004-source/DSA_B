#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


void insertFront(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}


void insertEnd(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}


void insertAtPosition(Node*& head, int value, int position) {
    if (position == 1) {
        insertFront(head, value);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}


void display(Node* head) {
    Node* temp = head;

    cout << "Queue: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    Node* head = NULL;

    int choice, value, position;

    do {
        cout << "\n--- Hospital Patient Queue ---\n";
        cout << "1. Add critical patient at front\n";
        cout << "2. Add routine patient at end\n";
        cout << "3. Insert patient at specific position\n";
        cout << "4. Display queue\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter patient token number: ";
            cin >> value;

            insertFront(head, value);
            display(head);
            break;

        case 2:
            cout << "Enter patient token number: ";
            cin >> value;

            insertEnd(head, value);
            display(head);
            break;

        case 3:
            cout << "Enter patient token number: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            insertAtPosition(head, value, position);
            display(head);
            break;

        case 4:
            display(head);
            break;

        case 5:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
