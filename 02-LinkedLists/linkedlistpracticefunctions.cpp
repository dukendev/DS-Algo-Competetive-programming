#include <iostream>

using namespace std;

class Node{
  public:
  int data;
  Node *next;

  Node(int n){
    data = n;
    next = NULL;
  }
};


//--------------------------------------------
void printlist(Node** head){
  Node* temp = *head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}
//----------------------------------------
//-------------------------------------------
void sortedinsert(Node** head,int data){
  Node * newnode = new Node(data);
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

//-------------------------------------------
void insertatend(Node** head, int n){
  Node* temp = new Node(n);

  if((*head) == NULL){
    *head = temp;
    return;
  }

  Node* temp1 = *head;
  while(temp1->next!=NULL){
    temp1 = temp1->next;
  }
  temp1->next = temp;

  return;

}

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
//-------------------------------------
void deleteduplicates(Node** head){
  Node * current  = *head;
  
  if(current == NULL){
    return;
  }

  while(current->next!=NULL){
    if(current->data == current->next->data){
      Node* temp = current->next->next;
      
      delete current->next;
      current->next = temp;
    }
    else{
      current = current->next;
    }
  }
}
//---------------------------------------
void MoveNode(Node** a,Node** b){
  Node * temp = *b;
  if(temp==NULL){
    return;
  }
  else{
    
    *b = temp->next;
    
    temp->next = *a;
    *a = temp;
    
  }
}
//------------------------------------
/*
void alternatesplit(Node* head,Node** aref,Node** bref){
   Node *a =NULL;
   Node *b = NULL;
   Node * current = head;
   while(current!=NULL){
    MoveNode(&a,&head);
    if(current!=NULL){
      MoveNode(&b,&head);
    }
    *aref = a;
    *bref = b;
   }
}
*/

void AlternatingSplit(Node* source,Node** aRef, Node** bRef) {
Node* a = NULL; // Split the nodes to these 'a' and 'b' lists
Node* b = NULL;
Node* current = source;
while (current != NULL) {
MoveNode(&a, &current); // Move a node to 'a'
if (current != NULL) {
MoveNode(&b, &current); // Move a node to 'b'
}
}
*aRef = a;
*bRef = b;
}

//-----------------------------------------
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
//==================================================
Node* sortedmerge(Node* a,Node* b){
  Node* result = NULL;
  Node* a_cur = a;
  Node* b_cur = b;
  while(1){
    
  }
}
//-----------------------------------------
int main(){
  Node *head;
  head = NULL;

  Node *A = NULL;
  Node *B = NULL;

  insertatend(&A,0);
  insertatend(&B,1);
  insertatend(&A,2);
  insertatend(&B,3);
  insertatend(&A,4);
  insertatend(&B,5);

  cout<<endl;
  printlist(&A);
  cout<<endl;
  printlist(&B);
  cout<<endl;



  head = shufflemerge(A,B);


  printlist(&head);

  cout<<endl;
  printlist(&A);
  cout<<endl;
  printlist(&B);


  



  return 0;



}