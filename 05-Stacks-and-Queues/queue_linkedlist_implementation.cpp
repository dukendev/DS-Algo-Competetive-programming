#include <bits/stdc++.h>

using namespace std;
//linked list implementation of queue 

class node{
public:
	int data;
	node* next;

	node(int x){
		data  =x;
		next = NULL;
	}
};

class lq{
	node* front;
	node* back;
public:
	lq(){
		front = NULL;
		back = NULL;
	}


	void push(int x){
		node* t = new node(x);

		if(!front){
			front = t;
			back = t;
			return;
		}

		back->next = t;
		back = back->next;
		return;
	}

	int pop(){
		if(!front){
			cout<<"Queue is empty";
			return -1;
		}
		int x;
		node* t = front;
		front = front->next;
		x = t->data;
		delete t;
		t= NULL;

		return x;
	}

	int peek(){
		if(!front){
			cout<<"No elements to show"<<endl;
			return -1;
		}
		return front->data;
	}

	void display(){
		node* t = front;
		while(t!=NULL){
			cout<<t->data<<" ";
			t=t->next;
		}
	}
};


int main(){

	lq q;

	q.push(2);
	q.push(4);
	q.push(6);
	q.push(8);
	q.push(10);
	q.display();
	q.pop();
	q.display();
	
	


	return 0;
}
