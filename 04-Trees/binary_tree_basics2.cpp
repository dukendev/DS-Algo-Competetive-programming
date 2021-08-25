//calcuting number of nodes of various degrees and hieght
//using height to for level order traversal
//level order traversal naive method not using queue
#include <bits/stdc++.h>
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
//find the height of the tree
int height_tree(node* root){
	if(root == NULL){
		return 0;
	}

	int left_h = height_tree(root->left);
	int right_h = height_tree(root->right);

	if(left_h>right_h){
		return left_h+1;
	}
	else
	{
		return right_h+1;
	}
}

//count the number of nodes
int count_all_nodes(node* root){
	if(root==NULL){
		return 0;
	}

	int x = count_all_nodes(root->left);
	int y = count_all_nodes(root->right);

	return x+y+1;
}



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

	cout<<height_tree(root);
	cout<<endl;
	cout<<count_all_nodes(root);

	return 0;
}