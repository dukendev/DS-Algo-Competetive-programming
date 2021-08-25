//in this program we will print all possible permutation of string
//print entire power set

#include <bits/stdc++.h>
using namespace std;

void solve(string input, string ouput){
	if(input.length() == 0){
		cout<<ouput<<" ";
		return;
	}

	string o1 = ouput;
	string o2 = ouput;
	o2.push_back(input[0]);
	input.erase(input.begin()+0);

	solve(input,o1);
	solve(input,o2);

	return;
}

int main(){

	string input = "abcde";
	string ouput = "";

	solve(input,ouput);
	return 0;
}