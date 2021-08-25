#include <iostream>

using namespace std;

//Node definition -------------------
struct Node{
  int data;
  Node* next;
};

int lengthoflist(Node* ); //prototyping
  //global pointer to Node ---------for ease of problems

void deleteatn(Node*& head,int n){
  Node* temp1 = head;
  if(n==1){
    head = temp1->next;
    delete temp1;
    return;
  }

  for ( int i = 0; i < n-2 ; i++){
    temp1 = temp1->next;
  }
  Node* temp2 = temp1->next;
  temp1->next = temp2->next;
  delete temp2;

}

//---------------------eof

void insertatn(Node** head,int a,int n){
  Node* temp = new Node();
  temp->data = a;
  if(n==1){
  
  temp->next = *head;
  *head = temp;
  return;
  }

  Node* temp1 = *head;
  for(int i = 0;i < n-2;i++){
    temp1 = temp1->next;
  }
  temp->next =temp1->next;
  temp1->next = temp;

}

//-------------------eof

void printlist(Node** head){

  cout<<"The list is : ";
  
  Node* temp1 = *head;
  while(temp1!=NULL){      //if temp1->next!=NULL  then 1 will not print and loop will break when temp1 will point last node and condition will not match so not print 1
    cout<< temp1->data<<" ";
    temp1 = temp1->next;
  }
  cout<<endl;
}

//----------------------
//function to count the frequency of the key

int countoccurance(Node*& head,int key){
  Node *temp = head;
  int count =0;
  while(temp!=NULL){
    if(temp->data == key){
      count++;
    }
    temp = temp->next;

  }
  return count;
}

//------------------------------------
//function returns nth index elements data in 0 based indexing
void getnth(Node*& head,int index){
  Node *temp = head;
  for(int i = 0; i < index;i++){
    temp = temp->next;
  }
  cout<<temp->data;

}
//------------------------------
//deletes all elements of list from the heap
void deletelist(Node*& head){
  Node * current = head;
  Node * nextptr = NULL;

  while(current!=NULL){
    nextptr = current->next;
    delete current;
    current = nextptr;
  }

  head = NULL;
  cout<<"List has been deleted from the memory";
}

//--------------------------------
//sort insert inserts new element in sorted list in correct position
void sortedinsert(Node** head,int data){
  Node * newnode = new Node();
  newnode->data = data;
  newnode->next = NULL;

  Node * curr = *head;
  if(*head==NULL || (*head)->data >= newnode->data){
    newnode->next = *head;
    *head = newnode;
  }
  else{
  while(curr->next!=NULL && curr->next->data < newnode->data){
    curr = curr->next;
  }
  newnode->next = curr->next;
  curr->next = newnode;
  }
  
}
//-----------------------------------------

void insertsort(Node ** head){
  Node * result;
  result = NULL;
  Node* current = *head;
  Node *nextptr;
  while(current!=NULL){
    nextptr = current->next;
    sortedinsert(&result,current->data);
    current = nextptr;
  }

  *head =result;


}
//-------------------------
void appendlists(Node** a_ref,Node** b_ref){
  if(*a_ref==NULL){
    *a_ref = *b_ref;
    *b_ref = NULL;
    return;
  }
  else{
    Node * cur = *a_ref;
    while(cur->next!=NULL){
      cur = cur->next;
    }
    cur->next = *b_ref;
    *b_ref = NULL;

  }
}
//-----------------------------
//splits the lists

void frontbacksplit(Node** head, Node** front,Node** back){
  int n = lengthoflist((*head));
  if(head==NULL){
    cout<<"empty list can't be split"<<endl;
  }
  else if(n==1){
    *front = *head;
    *back = NULL;
  }
  else{
    
    int x = (n+1)/2;
    Node* temp = *head;
    Node* prev = NULL;
    for(int i=2;i<=x;i++){
      temp = temp->next;
    }
     *back = temp->next;
     temp->next = NULL;
     *front = *head;
  }
}

//----------------------------
//calculates length of the list
int lengthoflist(Node* head){
  int length = 0;
  Node* temp = head;
  while(temp!=NULL){
    length++;
    temp = temp->next;
  }
  return length;

}

//------------------------------
//deteleduplicates from sorted

void deleteduplicates(Node** head){
  Node * current  = *head;
  Node * temp;
  while(current->next!=NULL){
    if(current->data == current->next->data){
      temp = current->next->next;
      
      delete current->next;
      current->next = temp;
    }
    else{
      current = current->next;
    }
  }
}

//---------------------------------
//Take the node from the front of the source, and move it to
 //the front of the dest.
void MoveNode(Node** a,Node** b){
  if(*b==NULL){
    return;
  }
  else{
    Node * temp = *b;
    *b = temp->next;
    
    temp->next = *a;
    *a = temp;
    
  }
}

//-----------------------------------------
void alternatesplit(Node* head,Node** aref,Node** bref){
   Node *a =NULL;
   Node *b = NULL;
   Node * current = head;
   while(current!=NULL){
    MoveNode(&a,&current);
    if(current!=NULL){
      MoveNode(&b,&current);
    }
    *aref = a;
    *bref = b;
   }
}
//------------------------------
Node* shufflemerge(Node* a,Node* b){
  Node * result = NULL;
  Node ** lastref = &result;

  while(1){

    if(a==NULL){
      *lastref = b;
      break;
    }
    else if(b==NULL){
      *lastref = a;
      break;
    }

    else{
      MoveNode(lastref, &a);
      lastref = &((*lastref)->next);
      MoveNode(lastref, &b);
      lastref = &((*lastref)->next);
    }
  }
  return result;
}
//-------------------------------------------

int main(){
  Node* head;
  head = NULL; //empty list with zero nodes 

  Node *A = NULL;
  Node *B = NULL;

  //Node* temp = new Node();
  //temp->data = 1;
  //temp->next = NULL;
  //head = temp;
 insertatn(&head,1,1);
 insertatn(&head,2,2);
 insertatn(&head,3,3);
 insertatn(&head,4,4);
 insertatn(&head,5,5);
 printlist(&head);

 alternatesplit(head,&A,&B);
 printlist(&head);
 printlist(&A);
 printlist(&B);
 
  return 0;
}

