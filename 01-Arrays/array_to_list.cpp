#include<bits/stdc++.h>

using namespace std;
//AB tuts make linked list from given array


//structure of Nodes for the linked list
struct Node
{
	int data;
	Node* next;

	Node(int x){
		data = x;
		next = NULL;
	}
};

//Displaying iteratively traversal in the linked list
void displaylist(Node* head){
	Node * temp = head;
	while(temp){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

//This function creates linked list from given array
Node* createlist(int a[],int n){
	Node* head;
	head = new Node(a[0]);
	Node* last = head;
	

	for(int i = 1;i < n ; i++){
		Node* temp = new Node(a[i]);
		last->next = temp;
		last = temp;
	}
	

	return head;
}

//This function display recurrsive traversal in the linked list
void rdisplay(Node* head){
	if(head){
		//rdisplay(head->next); recursive call before printing will reverse print because return time printing will happen
		cout<<head->data<<" ";
		rdisplay(head->next);
	}
	
}

//Counting Number of Nodes in list
int counter(Node* head){
	int c = 0;
	while(head){
		c++;
		head = head->next;
	}
	cout<<endl;
	return c;
}
//Sum of all variables iterative
int Sum(Node* head){
	int sum = 0;
	while(head){
		sum += head->data;
		head = head->next;
	}
	cout<<endl;
	return sum;
}

//Maximum of list
int Maxoflist(Node* head){
	int m = -1;
	while(head){
		m = max(m,head->data);
		head= head->next;
	}
	cout<<endl;
	return m;
}

//recursive min function
int Minoflist(Node* head){
	int m = INT_MAX;
	if(!head){
		return m;
	}
	m = Minoflist(head->next);
	if(m<head->data)
		return m;
	else{
		return head->data;
	}
}


int main(){
	int a[7] = {5,9,13,4,51,16,7};
	Node* head;
	head = createlist(a,7);
	displaylist(head);
	rdisplay(head);
	cout<<counter(head);
	cout<<Sum(head);
	cout<<Maxoflist(head)<<endl;
	cout<<Minoflist(head);
}