#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

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


void deleteValue(Node*& head, int value) {
    if (head == NULL) {
        cout << "Queue is empty!" << endl;
        return;
    }


    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Patient deleted." << endl;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }


    if (temp->next == NULL) {
        cout << "Patient not found!" << endl;
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    delete deleteNode;

    cout << "Patient deleted." << endl;
}


void display(Node* head) {
    if (head == NULL) {
        cout << "Queue is empty!" << endl;
        return;
    }

    Node* temp = head;

    cout << "Queue (Front to Back): ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


void reversePrint(Node* head) {
    if (head == NULL)
        return;

    reversePrint(head->next);

    cout << head->data << " ";
}

int main() {
    Node* head = NULL;

    int choice, value;

    do {
        cout << "\n--- Hospital Patient Queue ---" << endl;
        cout << "1. Add patient" << endl;
        cout << "2. Delete patient" << endl;
        cout << "3. Display queue (Front to Back)" << endl;
        cout << "4. Reverse print (Back to Front)" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter patient token: ";
            cin >> value;

            insertEnd(head, value);
            break;

        case 2:
            cout << "Enter token to delete: ";
            cin >> value;

            deleteValue(head, value);
            break;

        case 3:
            display(head);
            break;

        case 4:
            cout << "Queue (Back to Front): ";

            if (head == NULL)
                cout << "Queue is empty!";
            else
                reversePrint(head);

            cout << endl;
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
