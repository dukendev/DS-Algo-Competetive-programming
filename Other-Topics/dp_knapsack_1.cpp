//kanp sack problem this is recursion approach which is 
//foundation of DP
//we can inmprove this further later
#include <bits/stdc++.h>
using namespace std;

//

int knapsack(int wt[],int val[],int w,int n){
	if(n==0 || w==0){
		return 0;
	}
	if(wt[n-1]<=w){
		return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));

	}
	else if(wt[n-1]>w){
		return knapsack(wt,val,w,n-1);
	}

	return -1;
}

int main(){

	int wt[] = {1,2,3,4,2};
	int val[] = {20,30,40,20,10};
	int n = 5;
	int w = 6;
	cout<<knapsack(wt,val,w,n);

	return 0;
}