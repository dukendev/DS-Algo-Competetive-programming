//avl trees are balanced BSTs 
//Rotations are done for balancing the trees
//class created by barney 
#include <bits/stdc++.h>
using namespace std;

//Node class used for trees 
class treenode{
	int data;
	treenode* left;
	treenode* right;
// Constructor
	treenode(){
		int data = 0;
		left = NULL;
		right = NULL;
	}

//Parameterized constructor
	treenode(int x){
		int data = x;
		left = NULL;
		right = NULL;
	}
};

class AVL_tree
{
public:
	//every object will have this root
	treenode* root;
	//for intializing avl tree objects root with Null
	AVL_tree(){
		root = NULL;
	}

	//function to check is tree is empty or not
	//We dont need to pass to root in parameter it can excess the root 
	//as it is a member function of same class
	bool isEmpty(){
		if(root == NULL){
			return false;
		}
		return true;
	}

	//Function to calculate height of tree
	//same as any other tree --- here is it done using recursion
	//We will make it parameterized to calculate the height from any given node also
	int getHeight(treenode* r){
//base condition 
//threotically Null i.r empty tree height should be -1 but 
//my assumption is zero .. it does not change much 
		if(r==NULL){
			return 0;
		}
//recursive calls for finding left and right heights
		int l = getHeight(r->left);
		int r = getHeight(r->right);

		return (x>y)?x+1:y+1;
	}
//function for getting balance factor of a node
	int getBalanceFactor(treenode* r){
		if(r==NULL){
			return 0;
		}
		int lh = getHeight(r->left);
		int rh = getHeight(r->right);

		return (lh-rh);
	}
//Rotation functions 
	//basically rotation is just right and left but for insertions steps
	//particular sequence of rotation operation has 4 names
	// for deletion also it becomes 6 names 
	//will be first implement only right and left rotation functions
	//then later

//Right rotation function

treenode* rightRotate(treenode* r){
	//making pointer to nodes for maniputation
	treenode* t = r->left;
	treenode* temp = t->right;

	//making rotation
	t->right = r;
	r->left = temp;

	return t;
}
//left rotation function same logic as right rotation
treenode* leftRotate(treenode *r){
	treenode* t = r->right;
	treenode* temp = t->left;

	t->left = r;
	r->right = temp;

	return t;
}

treenode* insertNode(treenode* r,treenode* newNode){

	if(root ==NULL){
		r = newNode;
		return r;
	}

	if(newNode->data < r->data){
		r->left = insertNode(r->left, newNode);
	}
	else if(newNode->data > r->data){
		r->right = insertNode(r->right, newNode);
	}
	else{
		cout<<"No dulpicates are allowed/n";
		return r;
	}
//when control reaches here node it added
	//but tree is unbalanced
	//so we calculate balancing factor
	//to check what rotation is required
	int bf = getBalanceFactor(r);
//for LL rotation senario
	if(bf>1 && newNode->data < r->left->data){
		return rightRotate(r);
	}
//for RR rotation senario
	else if(bf<-1 && newNode->data > r->right->data){
		return leftRotate(r);
	}
//for LR rotation
	else if(bf>1 && newNode->data > r->left->data){
		r->left = leftRotate(r->left);
		return rightRotate(r);
	}
//for RL rotation
	else if(bf<-1 && newNode->data < r->right->data ){
		r->right = rightRotate(r->right);
		return leftRotate(r);
	}

}
	
};


int main()
{
	AVL_tree obj;
	treenode* t = new treenode(1);
	obj.root = obj.insertNode(obj.root,t);


	return 0;
}