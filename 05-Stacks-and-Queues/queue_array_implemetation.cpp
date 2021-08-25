#include <bits/stdc++.h>
using namespace std;
class aq{
 int front;
 int rear;
 int size=10;
 int *q;

//Better use for space can be done by restting front and rear 
 //whenever they touch full condition to -1 again
 // or use circular array ADT
 // in circular front and rear intialize with zero
 // then keep front index blank
 // front and rear equal then empty condition 
 // f = (f+1)%n for circular indexing


 //this is basic array queue not even using circular array 
 //worst implementation
public:

	aq(){
 	q = new int[size];
 	front = rear = -1;
 	}

	void enqueue(int x){
		if(rear==size-1){
			cout<<"queue is full"<<endl;
			return;
		}
		rear++;
		q[rear] = x;

		if(front==-1){
			front++;
		}
		
	}

	void dequeue(){
		
		if(front==-1 || front>rear){
			cout<<"empty "<<endl;
		}
		
		front++;
	}

	int peek(){
		if(front==-1 || front>rear){
			return -1;
		}
		return q[front];
		
	}



};


int main(){

	aq q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	cout<<q.peek();
	q.dequeue();

	cout<<q.peek();
	q.dequeue();

	cout<<q.peek();
	q.dequeue();

	cout<<q.peek();
	q.dequeue();

	return 0;
}


//Bari implementation of array queue
/*
#include <iostream>
using namespace std;
class Queue
{
private:
int front;
int rear;
int size;
int *Q;
public:
Queue(){front=rear=-1;size=10;Q=new int[size];}
Queue(int size){front=rear=-1;this-
>size=size;Q=new int[this->size];}
void enqueue(int x);
int dequeue();
void Display();
};
void Queue::enqueue(int x)
{
if(rear==size-1)
printf("Queue Full\n");
else
{
rear++;
Q[rear]=x;
}
}
int Queue::dequeue()
{
int x=-1;
if(front==rear)
printf("Queue is Empty\n");
else
{
x=Q[front+1];
front++;
}
return x;
}
void Queue::Display()
{
for(int i=front+1;i<=rear;i++)
printf("%d ",Q[i]);
printf("\n");
}
int main()
{
Queue q(5);
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
q.Display();
return 0;
}
*/