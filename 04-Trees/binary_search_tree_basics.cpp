//Creating binary search tree using insert function
//search function and delete function for binary search tree
//iterative and recursive both methods
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
	node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

//search function for BST using recursion
bool search(node* root,int k){
	if(root==NULL){
		cout<<"Not Found ";
		return false;
	}

	if(k==root->data){
		cout<<"Found ";
		return true;
	}
	else if(k < root->data){
		return search(root->left,k);
	}
	else
		return search(root->right,k);

}

//search iteratively
bool search2(node* root,int k){
	while(root){
		if(root->data == k){
			cout<<"Found";
			return true;
		}
		else if(k< root->data){
			root = root->left;
		}
		else 
			root= root->right;
	}

	cout<<"Not Found ";
	return false;
}

//insert iterative 
node* insert(node* root, int k){

	if(root==NULL){
		node* t = new node(k);
		root = t;
		return root;
	}

	node* tail;
	while(root){
		tail = root;
		if(k == root->data){
			return root;
		}
		else if(k < root->data){
			root = root->left;
		}
		else
			root = root->right;
	}
	node* t = new node(k);
	if(k<tail->data)
		tail->left =t;
	else
		tail->right = t;

	return root;
}

//recursive insetion on BST
node* insert2(node* root,int k){
	node* t;
	if(root==NULL){
		t = new node(k);
		return t;
	}


	if(k<root->data){
		root->left = insert2(root->left,k);
	}
	else 
		root->right = insert2(root->right,k);

	return root;
}


//Delete function for BST this function is not complete yet, predecessor and 
//succesor and height calculate functions are yet to be coded

node* Inorder_precessor(node* root){
	while(root && root->left){
		root=root->left;
	}

	return root;
}

node* Inorder_sucessor(node* root){
	while(root && root->right){
		root=root->right;
	}
	return root;
}

int height(node* root){
	if(root == NULL){
		return 0;
	}

	int x = height(root->left);
	int y = height(root->right);

	return x>y?x+1:y+1;
}

node* delete_rec(node* root,int k){

	if(root==NULL){
		return NULL;
	}

	if(root->left == NULL && root->right == NULL){
		delete root;
		return NULL;
	}


	if(k < root->data){
		root->left = delete_rec(root->left,k);
	}
	else if(k > root->data){
		root->right = delete_rec(root->right,k);
	}
	else{
		if(height(root->left)>height(root->right)){
			node* t = Inorder_precessor(root->left);
			root->data = t->data;
			root->left = delete_rec(root->left,t->data);
		}
		else{
			node* t = Inorder_sucessor(root->right);
			root->data = t->data;
			root->right = delete_rec(root->right,t->data);

		}
	}

	return root;
}

void Inorder_print(node* root){

	if(root==NULL){
		return;
	}
	
	Inorder_print(root->left);
	cout<<root->data<<" ";
	Inorder_print(root->right);


}

int main()
{
	node* root = NULL;
	root = insert2(root,23);
	insert2(root,2);
	insert2(root,4);
	insert2(root,1);
	insert2(root,10);
	insert2(root,12);
	insert2(root,16);
	insert2(root,30);

	Inorder_print(root);
	cout<<endl;
	delete_rec(root,4);
	Inorder_print(root);


	return 0;
}