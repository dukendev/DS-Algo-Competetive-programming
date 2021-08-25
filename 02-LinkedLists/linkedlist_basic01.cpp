#include <iostream>

using namespace std;


struct Node{
  int data;
  Node* next;
};

Node* head;  //global pointer to Node 

void insertatbegin(int a){
  Node* temp = new Node();
  temp->data = a;
  temp->next = head;
  head = temp;
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

  insertatbegin(2);
  insertatbegin(30);
  insertatbegin(41);

  printlist();

  return 0;
}