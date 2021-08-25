#include <bits/stdc++.h>
using namespace std;

//utility function for printing 
void printarray(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}

void swap(int *a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


//-----------------------------------------------------------------------------

//Using o(n) space to arrange alternate positive and negatives
//also maintaining the order
//Time complexity of this : O(n)
void solve1(int a[],int n){
	vector<int> positive;
	vector<int> negative;

	for(int i=0;i<n;i++){
		if(a[i]>=0)
			positive.push_back(a[i]);
		else
			negative.push_back(a[i]);
	}

	int n1 = positive.size();
	int n2 = negative.size();
	int i=0,j=0,k=0;

	while(i<n1 && j<n2){
		if(k%2==0)
			a[k++]=negative[i++];
		else
			a[k++]=positive[j++];
	}

	while(i<n2){
		a[k++]=negative[i++];
	}

	while(j<n1){
		a[k++]=positive[j++];
	}
}


//Space complexity is O(1) but the order is not maintained

void solve2(int a[],int n){

	int i =0,j=n-1;
	while(i<j){
		if(a[i]>=0){
			i++;
		}
		if(a[j]<0){
			j--;
		}
		else{
			swap(a[i],a[j]);
			i++;
		}
		
	}
	// now we have separated positives and negatives at other sides
	// j = n-1;
	// i =0;
	// while(i<j){
	// 	swap(a[i],a[j]);
	// 	j-=2;
	// 	i+=2;
	// }

}


int main()
{
	int a[] = {-2,-3,4,-5,14,-6,-8,-22,1};
	int n= sizeof(a)/sizeof(a[0]);
	printarray(a,n);
	solve2(a,n);
	cout<<endl;
	printarray(a,n);

	return 0;
}