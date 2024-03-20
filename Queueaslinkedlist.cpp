#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;
    Queue() {
        front = NULL;
        rear = NULL;
    }
   void enqueueatEnd(int data) {
        Node* new_node = new Node(data);
        if (rear == NULL) {
            front = new_node;
            rear = new_node;
        }
        else {
            rear->next = new_node;
            rear = new_node;
        }
    }
    void dequeuefromFront() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "Dequeued item is " << front->data << endl;
        if (front == rear) {
            front = NULL;
            rear = NULL;
        }
        else {
            front = front->next;
        }
        delete temp;
    }


    void peek() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
        }
        else {
            cout << front->data << " is at the front of the queue" << endl;
        }
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " <- ";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};

int main() {

    Queue q;
    int choice, data;
    do{
        cout <<"1.Enqueue at end"<<endl;
		cout <<"2.Delete from front"<<endl;
		cout <<"3.Peek"<<endl;
		cout <<"4.Display"<<endl;
		cout <<"5.Exit"<<endl;
        cout <<"Enter your choice:";
        cin >> choice;
        switch (choice) {
        case 1:
        	 cout << "Enter data to enqueue: ";
            cin >> data;
            q.enqueueatEnd(data);
            break;
        case 2:
            q.dequeuefromFront();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << "Exit...";
        default:
            cout << "Invalid choice";
            break;
        }
    }while (choice!=5);
    
    return 0;
}

