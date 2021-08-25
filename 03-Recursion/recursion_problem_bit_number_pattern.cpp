//given integer n, print n bit size number where every prefix contains
//more 1's than 0's
#include <bits/stdc++.h>
using namespace std;

void solve(int one,int zero,int n,string output){
	if(n==0){
		cout<<output<<endl;
		return;
	}
	string out1 = output;
	out1.push_back('1');
	solve(one+1,zero,n-1,out1);
	if(one>zero){
		string out2 = output;
		out2.push_back('0');
		solve(one,zero+1,n-1,out2);
	}
	return;

}


int main(){
	int n = 5;
	int one = 0;
	int zero = 0;
	string output = "";

	solve(one,zero,n,output);

	return 0;
}