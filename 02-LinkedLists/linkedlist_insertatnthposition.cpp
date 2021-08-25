#include <iostream>

using namespace std;


struct Node{
  int data;
  Node* next;
};

Node* head;  //global pointer to Node 

void insertatn(int a,int n){
  Node* temp = new Node();
  temp->data = a;
  if(n==1){
  
  temp->next = head;
  head = temp;
  return;
  }

  Node* temp1 = head;
  for(int i = 0;i < n-2;i++){
    temp1 = temp1->next;
  }
  temp->next =temp1->next;
  temp1->next = temp;

}

void printlist(){
  
  Node* temp1 = head;
  while(temp1!=NULL){      //if temp1->next!=NULL  then 1 will not print and loop will break when temp1 will point last node and condition will not match so not print 1
    cout<< temp1->data<<",";
    temp1 = temp1->next;
  }
  cout<<endl;
}



int main(){
  head = NULL; //empty list with zero nodes 

  Node* temp = new Node();
  temp->data = 1;
  temp->next = NULL;
  head = temp;

  insertatn(2,1);
  insertatn(30,1);
  insertatn(41,1);
  insertatn(50,2);
  insertatn(100,6);

  printlist();

  return 0;
}