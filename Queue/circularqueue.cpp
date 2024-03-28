#include<iostream>
#define max 4

using namespace std;


	class CircularQueue{
		public:
		int front;
		int rear;
		int queue[max]; 
			void MakeEmpty(){
			rear = max-1;
			front=max-1;
		}	
		
		bool IsEmpty(){
			if(rear== front){
				cout<<"Queue is Empty"<<endl;
				return true;
			}else return false;
		}
	
		bool IsFull(){
			if(front == (rear+1)%max){   // front = 0 
				cout<<"Queue is full"<<endl;
				return true;
			}else{
				return false;	
			} 
		}
		int enqueue(){
			if(!IsFull()){
				
				int item;
				cout<<"Enter the element to be enqueued: ";
				cin>>item;
				rear = (rear+1)%max;		//rear = 0		
				//cout<<"REAR  ->"<<rear<<endl;
				this->queue[this->rear] = item;
				//cout<<queue[rear]<<endl;
			}
		}
		void dequeue(){
			if(!IsEmpty()){
							
				front = (front+1)%max;
				cout<<"Deleted item is "<<queue[front]<<endl;
//				return queue[front];
				}
		}
		void traverse(){
			if(!IsEmpty()){				
			//cout<<"Front  ->"<<front<<endl;
			//cout<<"Rear   ->"<<rear<<endl;
			cout<<"Data in the circular queue is "<<endl;		
			for( int i = (front+1)%max; i != rear; i = (i+1)%max)
			{
			cout<<queue[i]<< ", ";
			}
			cout<<queue[rear]<<endl;
			cout<<"\t";
			}	
			cout<<endl;
		}
		};


	int main(){
		int ch;
		CircularQueue C;
		C.MakeEmpty();
		char y = 'y';
		label:
		cout<<"Enter an operation to be executed: "<<endl;;	
			cout<<"1.Make Empty\n";			
			cout<<"2.Enqueue\n";
			cout<<"3.Dequeue\n";
			cout<<"4.Traverse\n";
			cout<<"5.Is Full\n";
			cout<<"4.Is Empty\n";
			cout<<"7.Exit"<<endl;
		
		
		cin>>ch;
		switch(ch){			
			case 1:
				C.MakeEmpty();
			goto label;
			break;			
			case 2:
				C.enqueue();
			goto label;
			break;
			case 3:
				C.dequeue();
			goto label;
			break;
			case 4:
				C.traverse();
			goto label;
			break;
			case 5:
				if(C.IsFull()){
					cout<<"Queue is full";
				}else{
					cout<<"Queue is not full";
				}
			goto label;
			case 6:
				if(C.IsEmpty()){
					cout<<"Queue is empty";
				}else{
					cout<<"Queue is not empty";
				}
			goto label;
			
			default:
				exit(0);
			
			break;				
		}	
		return 0;		
	}
