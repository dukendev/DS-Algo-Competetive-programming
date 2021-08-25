//
#include <bits/stdc++.h>
using namespace std;


void solve(int open,int close,string out,vector<string> &v){
	
	if(open== 0 && close== 0){
		v.push_back(out);
		return;
	}

	if(open!=0){
		string out1 = out;
		out1.push_back('(');
		
		solve(open-1,close,out1,v);
		//return;
	}
	if(close > open){
		string out2 = out;
		out2.push_back(')');
		solve(open,close-1,out2,v);
		return;
	}

}


int main()
{
	int input = 4;
	int open = input;
	int close = input;
	string output = "";
	vector<string> v;
	solve(open,close,output,v);	

	for(auto i : v){
		cout<<i<<endl;
	}

	return 0;
}