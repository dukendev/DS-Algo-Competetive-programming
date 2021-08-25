//stack using STL to reverse a sentence
#include <bits/stdc++.h>
#include <stack>
using namespace std;


void reversesentence(string s){
  stack<string> res;
  

  for(int i=0; i < s.length();i++){
    string word = "";
    while(s[i]!=' ' && i<s.length()){
      word += s[i];
      i++;
    }
    res.push(word);
  }

  while(!res.empty()){
    cout<<res.top()<<" ";
    res.pop();
  }
}

int main(){

  string s = "Hello world to ameatur programmer";
  reversesentence(s);


  return 0;
}