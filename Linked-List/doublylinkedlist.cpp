#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class Doubly{
public:
    Node *head;
    Node *tail;

    Doubly(){
        head = NULL;
        tail = NULL;
    }

    void insertatHead(int data) {
        Node *new_node = new Node(data);
        if (head == NULL){
            head = new_node;
            tail = new_node;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    void insertatTail(int data) {
        Node *new_node = new Node(data);
        if (tail == NULL) {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void insertatSpecificPosition(int data, int position) {
        if (position == 1) {
            insertatHead(data);
            return;
        }
        Node *new_node = new Node(data);
        Node *temp = head;
        int current_position = 1;
        while (current_position < position - 1 && temp != NULL) {
            temp = temp->next;
            current_position++;
        }
        if (temp == NULL) {
            cout << "Position out of range" << endl;
            return;
        }
        new_node->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }

    void deleteatHead() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        cout << "Deleted item is " << head->data << endl;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        } else {
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteatEnd() {
        if (head == NULL) {
            cout << "List is empty "<< endl;
            return;
        }
        if (head->next == NULL) {
            cout << "Deleted item is " << head->data << endl;
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        Node *temp = tail->prev;
        cout << "Deleted item is " << tail->data << endl;
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void deleteatSpecificPosition(int position) {
        if (head == NULL) {
            cout << "List is empty "<< endl;
            return;
        }
        if (position == 1) {
            deleteatHead();
            return;
        }
        Node *temp = head;
        int currentPosition = 1;
        while (currentPosition < position - 1 && temp != NULL) {
            temp = temp->next;
            currentPosition++;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of range" << endl;
            return;
        }
        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete->next != NULL)
            toDelete->next->prev = temp;
        else
            tail = temp;
        cout << "Deleted item at position " << position << ": " << toDelete->data << endl;
        delete toDelete;
    }

    void Traverse() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};

int main() {
    Doubly dl;
    int choice, data, position;
    do{
        cout <<"1. Insert at head"<<endl;
		cout <<"2. Insert at tail"<<endl;
		cout <<"3. Insert at specific position"<<endl;
        cout <<"4. Delete at head"<<endl;
		cout <<"5. Delete at tail"<<endl;
		cout <<"6. Delete at specific position"<<endl;
        cout <<"7. Traverse"<<endl;
		cout <<"8. Exit"<<endl;
        cout <<"Enter your choice:";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            dl.insertatHead(data);
            break;
        case 2:
            cout << "Enter data to insert: ";
            cin >> data;
            dl.insertatTail(data);
            break;
        case 3:
            cout << "Enter position to insert: ";
            cin >> position;
            cout << "Enter data to insert: ";
            cin >> data;
            dl.insertatSpecificPosition(data, position);
            break;
        case 4:
            dl.deleteatHead();
            break;
        case 5:
            dl.deleteatEnd();
            break;
        case 6:
            cout << "Enter position to delete: ";
            cin >> position;
            dl.deleteatSpecificPosition(position);
            break;
        case 7:
            dl.Traverse();
            break;
        case 8:
            cout << "Exit...";
        default: 
            cout<<"Invalid Choice";
            break;
        }
	} while (choice!=8);
	
	return 0;
}
            

