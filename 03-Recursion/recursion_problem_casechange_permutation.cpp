#include <bits/stdc++.h>
using namespace std;
void solve(string in,string op){
	if(in.length()==0){
		cout<<op<<endl;
		return;
	}

	string o1 = op;
	string o2 = op;

	o1.push_back(in[0]);
	o2.push_back(in[0]-32);

	in.erase(in.begin()+0);

	solve(in,o1);
	solve(in,o2);

	return;

}

int main(){

	string input = "abcd";
	string output = "";

	solve(input,output);

	return 0;
}