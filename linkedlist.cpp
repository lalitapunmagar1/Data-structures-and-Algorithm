#include <iostream>
using namespace std;

class Node {
	public:
		
        int data;
        Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }
    
    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        }else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAtSpecificPosition(int value, int position) {
        Node* newNode = new Node;
        newNode->data = value;
        if (position == 1) {
            newNode->next = head;
            head = newNode;
        }else {
            Node* current = head;
            for (int i = 1; i < position - 1 && current != NULL; i++) {
                current = current->next;
            }
            if (current != NULL) {
                newNode->next = current->next;
                current->next = newNode;
            }else {
                cout << "Position out of range" << endl;
            }
        }
    }

    void deleteFromBeginning() {
        if (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteFromEnd() {
        if (head != NULL) {
            if (head->next == NULL) {
                delete head;
                head = NULL;
            } else {
                Node* current = head;
                while (current->next->next != NULL) {
                    current = current->next;
                }
                delete current->next;
                current->next = NULL;
            }
        }
    }

    void deleteFromSpecificPosition(int position) {
        if (position == 1) {
            deleteFromBeginning();
        }else {
            Node* current = head;
            Node* previous;
            for (int i = 1; i < position && current != NULL; i++) {
                previous = current;
                current = current->next;
            }
            if (current != NULL) {
                previous->next = current->next;
                delete current;
            } else {
                cout << "Position out of range" << endl;
            }
        }
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    int choice, value, position;

    do {
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at specific position" << endl;
        cout << "4. Delete from beginning" << endl;
        cout << "5. Delete from end" << endl;
        cout << "6. Delete from specific position" << endl;
        cout << "7. Display elements" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert: ";
                cin >> position;
                list.insertAtSpecificPosition(value, position);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteFromSpecificPosition(position);
                break;
            case 7:
                cout << "Linked list elements: ";
                list.display();
                break;
            case 8:
                cout << "Exit...";
                break;
            default:
                cout << "Invalid choice"<<endl;
        }
    } while (choice!=8);
    
    return 0;
}

