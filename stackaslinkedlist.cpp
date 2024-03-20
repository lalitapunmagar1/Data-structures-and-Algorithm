#include<iostream>
using namespace std;

		class Node{
			public:
		    int data;
		    Node* next;
		    Node(int data) {
		    this->data = data;
		    next = NULL;
		    }
		};
		
		class LinkedList{
			public:
		    Node* head;
		    LinkedList() {
		        head = NULL;
		    }
		    
		void pushatBeginning(int data){
			Node* new_node = new Node(data);	
			new_node->next = head;
			head = new_node; 
		}
	
		
		void deleteatHead() {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        cout<<"Deleted item is "<<head->data<<endl;
        head = head->next;
        delete temp;
 	    }
 	  
 	    
 	    void peek(){
 	    	if(head == NULL){
 	    		cout<<"Stack is empty"<<endl;
			 }else
			 cout<<head->data<<" is at top of Stack"<<endl;
		 }
		
		void display() {
        if(head == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "Null" << endl;
 		   }
		};
		
		int main(){
			
			LinkedList list;
            int choice, data;
            do{
            cout <<"1.Insert at head"<<endl;
			cout <<"2.Delete at head"<<endl;
			cout <<"3.Peek"<<endl;
			cout <<"4.Display"<<endl;
			cout <<"5.Exit"<<endl;
            cout <<"Enter your choice:";
            cin >> choice;
            switch(choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                list.pushatBeginning(data);
                break;
           
            case 2:
                list.deleteatHead();
                break;
           
            case 3:
            	list.peek();
            	break;
            case 4:
                list.display();
                break;      
            case 5:
                cout << "Exit...";
            default:
                cout << "Invalid choice" << endl;
        }
    }while (choice!=5);	
    
    return 0;
}
