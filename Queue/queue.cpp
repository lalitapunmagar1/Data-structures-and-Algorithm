#include<iostream>
#define max 6

using namespace std;

class Queue{
	public:
		int arr[max];
		int front;
		int rear;
		Queue(){
			this->rear=-1;
			this->front=0;
		}
		void MakeEmpty(){
			rear=-1;
			front=0;
		}
		int IsEmpty(){
			if(rear<front){
				return 1;
			}else{
				return 0;
			}
		}
		int IsFull(){
			if(rear==max-1){
				return 1;
			}else{
				return 0;
			}
		}
		void Enqueue(int item){
			if(IsFull()){
				cout<<"The queue is full"<<endl;
			}else{
				rear++;
				cout<<"Enter the item to be enqueued: ";
				cin>>item;
				arr[rear]=item;
			}
		}
		void Dequeue(){
			if(IsEmpty()){
				cout<<"The queue is empty"<<endl;
			}else{
				int temp=arr[front];
				front++;
				cout<<temp<<" is dequeued from the queue"<<endl;
			}
		}
		void Traverse(){
			cout<<"The items in the queue are: "<<endl;
			for(int i=front; i<=rear;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};

int main(){
	int choice=0;
	Queue q;
	do{
		cout<<"Enter the operation to be executed: "<<endl;
		cout<<"1. Make Empty"<<endl;
		cout<<"2. Check if queue is empty"<<endl;
		cout<<"3. Check if queue is full"<<endl;
		cout<<"4. Enqueue"<<endl;
		cout<<"5. Dequeue"<<endl;
		cout<<"6. Traverse"<<endl;
		cout<<"7. Exit"<<endl;
		cin>>choice;
		
		switch(choice){
			case 1:
				q.MakeEmpty();
				break;
			case 2: 
				if(q.IsEmpty()){
					cout<<"The queue is empty."<<endl;
				}else{
					cout<<"The queue is not empty"<<endl;
				}
				break;
			case 3:
				if(q.IsFull()){
					cout<<"The queue is full."<<endl;
				}else{
					cout<<"The queue is not full"<<endl;
				}
				break;
			case 4:
				int var;
				q.Enqueue(var);
				break;
			case 5:
				q.Dequeue();
				break;
			case 6:
				q.Traverse();
				break;
			default:
				choice=7;
		}
	}while(choice!=7);
	return 0;
}
