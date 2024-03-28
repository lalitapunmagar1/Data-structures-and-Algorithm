#include <iostream>

using namespace std;

class Node{
public:
    Node *next;
    int data;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class CircularLinkList{
    Node *head;

public:
    CircularLinkList(){
        this->head = NULL;
    }

    void insertAtBeginning(int data){
        Node *newNode = new Node(data);

        if (head == NULL){
            head = newNode;
            newNode->next = head;
            return;
        }

        Node *currentNode = head;

        while (currentNode->next != head){
            currentNode = currentNode->next;
        }

        newNode->next = head;
        head = newNode;
        currentNode->next = head;
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL){
            head = newNode;
            newNode->next = head;
            return;
        }

        Node *currentNode = head;
        while (currentNode->next != head)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
        newNode->next = head;
    }

    void insertAtSpecificPosition(int position, int value) {
        Node *newNode = new Node(value);
        newNode->data = value;
        if (head == NULL){
            head = newNode;
            newNode->next = newNode;
        }else{
            if (position == 1){
                head->next = newNode;
                newNode->next = head;
                head = newNode;
            }else{
                Node *currentNode = head;
                for (int i = 1; i < position - 1 && currentNode->next != head; i++) {
                    currentNode = currentNode->next;
                }

                if (currentNode->next == NULL){ 
                    currentNode->next = newNode;
                    newNode->next=head;
                }
                else if(currentNode->next->next != NULL){
                    newNode->next=currentNode->next;
                    currentNode->next=newNode;
                } else{
                    cout << "Position out of range" << endl;
                }
            }
        }
    }

    void deleteFirst(){
        if (head == NULL){
            cout << "Empty" << endl;
            return;
        }

        if (head->next == head){
            head = NULL;
            return;
        }

        Node *temp = head;
        Node *currentNode = head->next;
        while (currentNode->next != head){
            currentNode = currentNode->next;
        }

        currentNode->next = head->next;
        head = head->next;
        delete (temp);
    }

    void deleteLast(){
        if (head == NULL){
            cout << "Empty" << endl;
            return;
        }

        if (head->next == head){
            head = NULL;
            return;
        }

        Node *currentNode = head->next;
        while (currentNode->next->next != head){
            currentNode = currentNode->next;
        }

        Node *temp = currentNode->next;
        currentNode->next = head;
        delete (temp);
    }

    void deleteFromSpecificPosition(int position){
        if (position == 1){
            deleteFirst();
        }
        else{
            Node *currentNode = head;
            Node *previous;
            for (int i = 1; i < position - 1 && currentNode != NULL; i++){
                previous = currentNode;
                currentNode = currentNode->next;
            }
            if (currentNode != NULL){
                previous->next = currentNode->next;
                delete currentNode;
            }
            else{
                cout << "Position out of range" << endl;
            }
        }
    }

    void display()
    {
        if (head == NULL){
            cout << "Empty" << endl;
            return;
        }

        Node *currentNode = head;

        cout << currentNode->data << " -> ";
        currentNode = currentNode->next;

        while (currentNode != head){
            cout << currentNode->data << " -> ";
            currentNode = currentNode->next;
        }
        cout << " NULL" << endl;
    }
};

int main()
{
    CircularLinkList list;
    int choice, value, position;
    do
    {
        cout << "1. Insert at beginning " << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at specific position" << endl;
        cout << "4. Delete from beginning" << endl;
        cout << "5. Delete from end" << endl;
        cout << "6. Delete from specific position" << endl;
        cout << "7. Traverse" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position to insert: ";
            cin >> position;
            list.insertAtSpecificPosition(position, value);
            break;
        case 4:
            list.deleteFirst();
            break;
        case 5:
            list.deleteLast();
            break;
        case 6:
            cout << "Enter the position to delete: ";
            cin >> position;
            list.deleteFromSpecificPosition(position);
            break;
        case 7:
            list.display();
            break;
        case 8:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 8);
    return 0;
}
