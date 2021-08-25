//In this program we will solve matrix chain multiplication
#include <bits/stdc++.h>
using namespace std;
//using naive recurcive approach

int matrixChainMultiplication(int a[],int i,int j){
	
	
	if(i==j){
		return 0;
	}

	int k;
	int min = INT_MAX;
	int count;

	for(k=i;k<j;k++){
		count = matrixChainMultiplication(a,i,k) +
				matrixChainMultiplication(a,k+1,j) +
				a[i-1]*a[k]*a[j];
		if(count<min){
			min = count;
		}

	}

	return min;

}

int main(){
	int a[] = {10,20,30,40,10,50};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<matrixChainMultiplication(a,1,n-1);

	return 0;
}