#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *previous;

    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->previous = NULL;
    }
};

class DoublyCircularLinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void InsertAtBegin(int x)
    {
        Node *newNode = new Node;

        if (head == NULL)
        {
            head = newNode;
            newNode->next = newNode;
            newNode->previous = newNode;
            tail = newNode;

            newNode->data = x;
        }
        else 
        {
            head->previous = newNode; 
            newNode->next = head; 
            head = newNode;

            tail->next = head;
            head->previous = tail;

            newNode->data = x; 
        }
    }

    void InsertAtEnd(int x)
    {
        Node *newNode = new Node;

        if (head == NULL) 
        {
            head = newNode;
            newNode->next = newNode;
            newNode->previous = newNode;
            tail = newNode;

            newNode->data = x;
        }
        else 
        {
            Node *newNode = new Node;

            newNode->previous = tail; 
            tail->next = newNode;  

            tail = newNode; 

            tail->next = head;
            head->previous = tail;

            newNode->data = x; 
        }
    }

    void InsertAtMiddle(int x, int ind)
    {
        Node *newNode = new Node;
        int i = 0;

        Node *temp = head;
        while (i < ind - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next; 
        temp->next = newNode;       

        newNode->previous = temp;
        newNode->next->previous = newNode;

        newNode->data = x; 
    }

    void TraverseNext()
    {
        Node *temp;
        for (temp = head; temp != tail; temp = temp->next)
        {
            cout << temp->data;
        }
        cout << endl;
    }

    void TraversePrevious()
    {
        Node *temp;
        for (temp = tail; temp != head; temp = temp->previous)
        {
            cout << temp->data;
        }
        cout << endl;
    }

    void DeleteFromBegin()
    {
        if (head == NULL)
        {
            cout << "The list is empty." << endl;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            if (head->next != head)
            {
                head->previous = tail;
                tail->next = head;
            }
            else
            {
                tail = NULL;
                head = NULL;
            }
            delete temp;
        }
    }

    void DeleteFromEnd()
    {
        if (head == NULL)
        {
            cout << "The list is empty." << endl;
        }
        else
        {
            Node *temp = tail;
            tail = tail->previous;
            if (tail->previous != tail)
            {
                tail->next = head;
                head->previous = tail;
            }
            else
            {
                tail = NULL;
                head = NULL;
            }
            delete temp;
        }
    }

    void DeleteFromMiddle()
    {
        if (head == NULL)
        {
            cout << "The list is empty." << endl;
        }
        else
        {
            int ind;
            cout << "Enter the position to delete: ";
            cin >> ind;

            Node *temp;
            int i = 0;
            for (i = 0, temp = head; (i < ind - 1) && (temp->next->next != head); i++, temp = temp->next)
                ;
            Node *toDel = temp->next;
            if (temp->next->next == head)
            {
                tail = temp;
                tail->next = head;
                head->previous = tail;
            }
            else
            {
                temp->next = temp->next->next;
                temp->next->previous = temp;
            }

            delete toDel;
        }
    }

    void mainProcess()
    {
        int choice;
        do{
            cout<< "1. Insert at front" << endl;
            cout<< "2. Insert at back" << endl;
            cout<< "3. Insert in between" << endl;
            cout<< "4. Traverse from front" << endl;
            cout<< "5. Traverse from back" << endl;
            cout<< "6. Delete from front" << endl;
            cout<< "7. Delete from back" << endl;
            cout<< "8. Delete from between" << endl;
            cout<< "9. Exit the program" << endl;
                 
            cout<<"Enter the operation you want to execute:";  
            cin >> choice;
            switch (choice)
            {
            case 1:
                int valb;
                cout << "Enter a number to input: ";
                cin >> valb;
                InsertAtBegin(valb);
                break;

            case 2:
                int vale;
                cout << "Enter a number to input: ";
                cin >> vale;
                InsertAtEnd(vale);
                break;

            case 3:
                int valm, pos;
                cout << "Enter a number to input: ";
                cin >> valm;
                cout << "Enter a position : ";
                cin >> pos;
                InsertAtMiddle(valm, pos);
                break;

            case 4:
                TraverseNext();
                break;

            case 5:
                TraversePrevious();
                break;

            case 6:
                DeleteFromBegin();
                break;

            case 7:
                DeleteFromEnd();
                break;

            case 8:
                DeleteFromMiddle();
                break;

            case 9:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid input" << endl;
                break;
            }
        } while (choice!= 9);
    }
};

int main()
{
    DoublyCircularLinkedList d;
    d.mainProcess();
}

