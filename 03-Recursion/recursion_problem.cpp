//given 
// 0
// 01
// 0110
// 01101001
//n is row, k is colum
//next row 0 changes to 01 and 1 changes to 10
//solve for any given n and k
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k) {
	if(n==1 && k==1){
		return 0;
	}

	int mid = pow(2,n-1)/2;
	if(k<=mid){
		return solve(n-1,k);
	}
	else
		return !(solve(n-1,k-mid));
}

int main()
{
	cout<<solve(4,3);
	return 0;
}