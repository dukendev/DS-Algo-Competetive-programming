
#include <bits/stdc++.h>
using namespace std;
//Node used to make our linked list
class node{
public:
	int data;
	node* next;

	node(int x){
		data = x;
		next= NULL;
	}
};

//Class of our singly linked list with functions
//insertion at head is done in constant time
//insertion at tail will be linear
//deletion is linear for nth node


class mySinglyLinkedList{
	//head node for every object of this class
	node* head = NULL;
public:
	//add node at the start
	void insert(int x){
		node* t = new node(x);
		if(head==NULL){
			head = t;
		}
		else{
		node* nextnode = head;
		t->next = nextnode;
		head = t;
		}
	}


	void display(){
		node* t = head;
		while(t!=NULL)
		{	

			cout<<t->data<<" ";
			t = t->next;
		}

	}

	void deleteNth(int n){
		node* toDelete = head;
		if(!head){
			return;
		}
		
		else if(n==1){
			head = head->next;
			delete toDelete;
			toDelete = NULL;
		}
		else{
			for(int i = 0 ; i < n-2;i++){
				toDelete = toDelete->next;
			}
			node* t = toDelete->next;
			toDelete->next = t->next;
			delete t;
			t=NULL;
		}
	}

	void reverse_iterative(){

		if(head==NULL || head->next==NULL){
			return;
		}
		node* current_ptr = head;
		node *prev_ptr = NULL;
		node* next_ptr = NULL;

		while(current_ptr!=NULL){
			next_ptr = current_ptr->next;
			//reverse link here
			current_ptr->next = prev_ptr;

			prev_ptr = current_ptr;
			current_ptr = next_ptr;
		}

		head = prev_ptr;
	}


};

/*
class myDoublylist(){
	node* head = NULL;
public:


};
*/

int main(){

	mySinglyLinkedList l;
	l.insert(1);
	l.insert(2);
	l.insert(6);
	l.insert(8);
	l.insert(5);
	

	l.display();
	l.reverse_iterative();
	l.display();
	return 0;
}