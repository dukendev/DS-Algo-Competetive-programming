//Design a stack with operations on middle element
#include <bits/stdc++.h>
using namespace std;

//Node of doubly linked list
class node{
public:
	node* prev;
	int data;
	node* next;
};

//stack class
class dll_stack{
public:
	node* head;
	node* mid;     //for maintaining the mid node
	int count; //counting nummber of nodes
};

dll_stack* createstack(){
	dll_stack* s = new dll_stack();
	s->count = 0;
	return s;
}

void push(dll_stack* s,int x){
	node* t = new node();
	t->data = x;

	t->prev = NULL;

	t->next = s->head;

	s->count +=1;

	if(s->count == 1){
		s->mid = t;
	}
	else{
		s->head->prev = t;
		if((s->count)%2==0){
			s->mid = s->mid->prev;
		}
	}

	s->head = t;
}

int pop(dll_stack* s){
	if(s->count==0){
		cout<<"list is empty "<<endl;
		return -1;
	}

	node* temp = s->head;
	int x = temp->data;
	s->head = temp->next;


	if(s->head!=NULL){
		s->head->prev = NULL;
	}
	s->count -=1;

	if((s->count)%2==1){
		s->mid = s->mid->next;
	}

	delete temp;
	temp = NULL;

	return x;
}


int findMidNode(dll_stack* s){
	if(s->head==NULL){
		return -1;
	}

	return s->mid->data;
}

int deletemid(dll_stack* s){

	int temp = s->mid->data;
	s->mid->prev->next = s->mid->next;
	s->mid->next->prev = s->mid->prev->next;

	delete s->mid;
	s->mid = s->mid->next;

	return temp;
}

int main()
{
    /* Let us create a stack using push() operation*/
    dll_stack* ms = createstack();
    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);
 
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Middle Element is " << findMidNode(ms) << endl;
    cout << "Deleted Middle Element is "<<deletemid(ms)<<endl;
    cout << "Middle Element is " << findMidNode(ms) << endl;
    return 0;
}