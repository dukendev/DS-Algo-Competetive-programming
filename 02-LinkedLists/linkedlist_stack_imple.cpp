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


class lstack{

	node* top=NULL;
public:


	void push(int x){
		node* t = new node(x);
		if(t){
			t->next = top;
			top = t;
			
		}
	}

	void display(){
		node* t = top;
		while(t){
			cout<<t->data<<" ";
			t = t->next;
		}
	}


	void pop(){
		node* t = top;
		top = top->next;
		delete t;
		t=NULL;
	}


};


int main(){

	lstack s;
	s.push(10);
	s.push(2);
	s.push(13);

	s.display();
	s.pop();
	s.display();

	return 0;
}