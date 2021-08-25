//this linked list uses dynamic memory 
#include <bits/stdc++.h>

using namespace std;


class node{
public:
	int data;
	node* next;

	node(int x){
		data = x;
		next = NULL;
	}
};

class mylinkedliststack {

	node* top = NULL;

	public:

	void pop();
	void push(int);
	int peek();
	bool isempty();

};

void mylinkedliststack::pop(){
	if(top==NULL){
		cout<<"Stack Underflow"<<endl;
		return;
	}
	node* todel;
	todel = top;
	top = top->next;
	delete todel;
}

void mylinkedliststack::push(int x){
	node* temp = new node(x);
	if(top==NULL){
		top = temp;
		return;
	}

	temp->next = top;
	cout<<temp->data<<" pushed in the stack "<<endl;
	top = temp;
}

int mylinkedliststack::peek(){
	if(top==NULL){
		cout<<"list is empty"<<endl;
		return -1;
	}
	return top->data;
}

bool mylinkedliststack::isempty(){
	if(top==NULL){
		return false;
	}
	return true;
}




int main(){

	mylinkedliststack s;

	s.push(1);
	s.push(2);
	s.push(3);

	
	




	return 0;
}