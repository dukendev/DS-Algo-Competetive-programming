//in this file we see the methods of generating binary trees
//from given preorder and inorder arrays
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

int search(int inorder[],int s,int e,int k){
	for(int i = s;i < e;i++){
		if(inorder[i]==k){
			return i;
		}
	}

	return -1;
}

node* create_pre_and_in(int preorder[],int inorder[],int s,int e){

	static int idx = 0;

	if(s>e){
		return NULL;
	}

	node* t = new node(preorder[idx++]);

	if(s==e){
		return t;
	}
	int pos = search(inorder,s,e,t->data);
	t->left = create_pre_and_in(preorder,inorder,s,pos-1);
	t->right= create_pre_and_in(preorder,inorder,pos+1,e);


	return t;

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
	node* root;
	int inorder[] = {4,2,5,1,6,3,7};
	int preorder[] = {1,2,4,5,3,6,7};

	root = create_pre_and_in(preorder,inorder,0,6);
	Inorder_print(root);

	return 0;
}