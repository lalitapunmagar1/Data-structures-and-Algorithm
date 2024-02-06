#include<iostream>
using namespace std;
#define max 6


class Queue{
  int arr[max];
  int rear;
  int front;

public:
  Queue(){
    this->rear=-1;
    this->front=0;
  }
  
  void make_empty(){
    rear=-1;
    front=0;
  }

  int checkempty(){
    if (front>rear)
    return 1;
    else return 0;
    }

    int checkfull(){
      if (rear==(max-1))
      return 1;
      else return 0;
    }

    void enter_data(){
      if(checkfull()){
        cout<<"Queue is full"<<endl;
      }else{
        ++rear;
        cout<<"Enter the data : "<<endl;
        cin>>arr[rear];
      }
    }

    void delete_data(){
      if(checkempty())
      cout<<"Queue is empty"<<endl;
      else ++front;
    }

    void traverse(){
      if(checkempty()){
      cout<<"No data to show "<<endl;
      }
      else{
      cout<<"The data required are : ";
      for(int i=front;i<=rear;++i){
        cout<<arr[i]<<" ";
      }
      cout<<endl;
    }
    }
  };

  int main(){
	int n=0;
	Queue q;
    cout<<"Enter the operation you want to execute:"<<endl;
	cout<<"Press 1. To make the queue empty"<<endl;
	cout<<"Press 2. To check the queue is empty or not"<<endl;
	cout<<"Press 3. To check the queue is full or not"<<endl;
	cout<<"Press 4. To insert the data into the queue"<<endl;
	cout<<"Press 5. To delete the data from the queue"<<endl;
	cout<<"Press 6. To see the queue "<<endl;
	cout<<"7. exit"<<endl;

	do{
			cin>>n;
		switch(n){
			case 1:
      q.make_empty();
				break;
		case 2:
		if(q.checkempty()){
			cout<<"The given data is empty"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}	
	break;
	case 3:
				if(q.checkfull()){
			cout<<"The given data is full"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}	
	break;
	case 4:
		q.enter_data();
		break;
		case 5:
;
			q.delete_data();
			break;
			case 6:
				q.traverse();
				break;
				default:
					n=8;
}
}while(n!=8);
return 0;
}
