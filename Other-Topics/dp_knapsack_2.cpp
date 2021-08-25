//this is done with memorization
#include <bits/stdc++.h>
using namespace std;

//we initialize dp matrix for memorization here;
//int dp[n+1][w+1];
// initialize it with -1


int knapsack(int wt[],int val[],int w,int n){
	if(n==0 || w==0){
		return 0;
	}
	//if(dp[n][w]!=-1){
	// return dp[n][w];

	if(wt[n-1]<=w){
		return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
		//return dp[n][w] = max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
	}
	else if(wt[n-1]>w){
		return knapsack(wt,val,w,n-1);
		//return dp[n][w] = knapsack(wt,val,w,n-1);
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