//print given string with all the space permutations
// abc -- a bc, ab c, ...



#include <bits/stdc++.h>
using namespace std;

//this function gives space permutations
void solve1(string input,string output){
	if(input.length()==0){
		cout<<output<<endl;
		return;
	}

	string o1 = output;
	string o2 = output;

	o1.push_back(input[0]);
	o2.push_back(' ');
	o2.push_back(input[0]);


	input.erase(input.begin()+0);

	solve(input,o1);
	solve(input,o2);

	return;
}




int main(){

	string input = "abcd";

	string output = "";
	output.push_back(input[0]);
	input.erase(input.begin()+0);

	solve1(input,output);


	return 0;
}