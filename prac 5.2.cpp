#include <iostream>
using namespace std;


class SNode
{
public:
    string name;
    SNode* next;

    SNode(string n)
    {
        name = n;
        next = NULL;
    }
};


class DNode
{
public:
    string name;
    DNode* next;
    DNode* prev;

    DNode(string n)
    {
        name = n;
        next = NULL;
        prev = NULL;
    }
};

class CircularLists
{
    SNode* shead;
    DNode* dhead;

public:
    CircularLists()
    {
        shead = NULL;
        dhead = NULL;
    }

   

    void addSingly(string name)
    {
        SNode* newNode = new SNode(name);

        if (shead == NULL)
        {
            shead = newNode;
            newNode->next = shead;
        }
        else
        {
            SNode* temp = shead;

            while (temp->next != shead)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = shead;
        }
    }

    void removeSingly(string name)
    {
        if (shead == NULL)
            return;

        // Only one student
        if (shead->next == shead)
        {
            if (shead->name == name)
            {
                delete shead;
                shead = NULL;
            }
            return;
        }

        SNode* previous = shead;
        SNode* current = shead->next;

        // Delete first student
        if (shead->name == name)
        {
            while (previous->next != shead)
            {
                previous = previous->next;
            }

            SNode* temp = shead;
            shead = shead->next;
            previous->next = shead;

            delete temp;
            return;
        }

        
        while (current != shead && current->name != name)
        {
            previous = current;
            current = current->next;
        }

        if (current != shead)
        {
            previous->next = current->next;
            delete current;
        }
    }

    void displaySingly()
    {
        cout << "Singly Circular: ";

        if (shead == NULL)
        {
            cout << "Empty";
        }
        else
        {
            SNode* temp = shead;

            do
            {
                cout << temp->name << " ";
                temp = temp->next;
            }
            while (temp != shead);
        }

        cout << endl;
    }


    

    void addDoubly(string name)
    {
        DNode* newNode = new DNode(name);

        if (dhead == NULL)
        {
            dhead = newNode;
            dhead->next = dhead;
            dhead->prev = dhead;
        }
        else
        {
            DNode* last = dhead->prev;

            newNode->next = dhead;
            newNode->prev = last;

            last->next = newNode;
            dhead->prev = newNode;
        }
    }

    void removeDoubly(string name)
    {
        if (dhead == NULL)
            return;

        DNode* current = dhead;

        do
        {
            if (current->name == name)
                break;

            current = current->next;

        }
        while (current != dhead);

        if (current->name != name)
            return;

        // Only one student
        if (current->next == current)
        {
            delete current;
            dhead = NULL;
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;

            if (current == dhead)
            {
                dhead = current->next;
            }

            delete current;
        }
    }

    void displayDoubly()
    {
        cout << "Doubly Circular: ";

        if (dhead == NULL)
        {
            cout << "Empty";
        }
        else
        {
            DNode* temp = dhead;

            do
            {
                cout << temp->name << " ";
                temp = temp->next;
            }
            while (temp != dhead);
        }

        cout << endl;
    }


   
    {
        displaySingly();
        displayDoubly();
        cout << endl;
    }
};


int main()
{
    CircularLists c;

  
    cout << "A joins:" << endl;
    c.addSingly("A");
    c.addDoubly("A");
    c.displayBoth();

    cout << "B joins:" << endl;
    c.addSingly("B");
    c.addDoubly("B");
    c.displayBoth();

    cout << "C joins:" << endl;
    c.addSingly("C");
    c.addDoubly("C");
    c.displayBoth();

    
    cout << "B leaves:" << endl;
    c.removeSingly("B");
    c.removeDoubly("B");
    c.displayBoth();

    cout << "D joins:" << endl;
    c.addSingly("D");
    c.addDoubly("D");
    c.displayBoth();

   
    cout << "A leaves:" << endl;
    c.removeSingly("A");
    c.removeDoubly("A");
    c.displayBoth();

    return 0;
}