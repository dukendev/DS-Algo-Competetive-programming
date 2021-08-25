//Here we make binary tree using defined nodes
//then recursive traversals pre,in,post
//iterative transversals
//level order transversal using queue
#include <bits/stdc++.h>
#include <stack>
using namespace std;

struct  node
{
	int data;
	node* left;
	node* right;

	node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

void Inorder_print(node* root){

	if(root==NULL){
		return;
	}

	Inorder_print(root->left);
	cout<<root->data<<" ";
	Inorder_print(root->right);


}

void preorder_print(node* root){

	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";
	preorder_print(root->left);
	preorder_print(root->right);


}

//pre_order traversal iteratively
void preorder_iterative(node* root){

	stack<node*> s;

	while(root!=NULL || s.empty() == false){
		if(root!=NULL){
			cout<<root->data<<" ";
			s.push(root);
			root = root->left;
		}
		else{
			root = s.top();
			s.pop();
			root = root->right;
		}
	}

}

void Inorder_iterative(node* root){

	stack<node*> s;

	while(root!=NULL || s.empty() == false){
		if(root!=NULL){
			s.push(root);
			root = root->left;
		}
		else{
			root = s.top();
			s.pop();
			cout<<root->data<<" ";
			root = root->right;
		}
	}

}

//iteratively using a queue
void levelorder(node* root){
	queue<node*> q;
	
	q.push(root);
	while(q.empty() == false){
		root = q.front();
		cout<<root->data<<" ";
		q.pop();
		if(root->left){
			q.push(root->left);
		}
		if(root->right){
			q.push(root->right);
		}
		

	}
}

//


int main()
{
	node* root;
	root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	/*
			1
		   / \
		  2   3
		 / \ / \
		4  5 6  7
	*/
	//printing pre-order
	preorder_print(root);
	cout<<endl;
	preorder_iterative(root);
	cout<<endl;
	Inorder_print(root);
	cout<<endl;
	Inorder_iterative(root);
	cout<<endl;
	levelorder(root);
	return 0;
}