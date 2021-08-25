//stack implementation using array
#include <bits/stdc++.h>
using namespace std;
#define n 20



class mystack{
	int top;
	int* arr;
	public :
	mystack(){
		arr = new int[n];
		top = -1;
	}

	void push(int x){
		if(top==n-1){
      cout<<"stack is full"<<endl;
      return;
    }
    top++;
    arr[top] = x;
	}

	void pop(){
    if(top==-1){
      cout<<"no elements"<<endl;
      return;
    }
		top--;
	}

	int givetop(){

		if(top==-1){
			cout<<"stack has no elements";
      return -1;
		}
		
		return arr[top];
	}

	bool isempty(){
		return top==-1;
	}
};

int main(){

	mystack s;
	s.push(1);
	s.push(3);
	s.push(7);
	s.pop();
	cout<<s.givetop();
	s.pop();
	s.pop();
	cout<<s.isempty();

	return 0;
}