//josephus problem circle of death, given circle of n people
//if every person kills its kth person who will be the last
//man standing

#include <bits/stdc++.h>
using namespace std;

void solve(int index,int k,vector<int> v){
	if(v.size()==1){
		cout<<v[0];
		return;
	}
	index = (index+k)%v.size();
	v.erase(v.begin()+index);
	solve(index,k,v);

	return;
}


int main(){
	int n =40;
	int k = 7;
	k--;

	vector<int> v;
	for(int i=1;i<=n;i++){
		v.push_back(i);
	}
	int index =0;
	solve(index,k,v);
	
	return 0;
}