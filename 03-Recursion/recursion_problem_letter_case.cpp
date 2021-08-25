//In this problem we can have any string with upper and lower case 
//includes digtis also then we generate case change permutations
#include <bits/stdc++.h>
using namespace std;

void solve(string in,string ot,vector<string> &v){
	
	if(in.length()==0){
		v.push_back(ot);
		return;
	}

	if(isalpha(in[0])){
		string o1 = ot;
		string o2 = ot;

		o1.push_back(tolower(in[0]));
		o2.push_back(toupper(in[0]));

		in.erase(in.begin()+0);

		solve(in,o1,v);
		solve(in,o2,v);

		return;
	}
	else{
		string o = ot;
		o.push_back(in[0]);
		in.erase(in.begin()+0);

		solve(in,o,v);

		return;
	}

}

int main()
{
	string input = "a1BcD2";
	string output = "";
	vector<string> v;
	solve(input,output,v);	

	for(auto i : v){
		cout<<i<<endl;
	}

	return 0;
}