//IN this program we will implement heap and heapsort using array representation
//for convienice let's use 1 based index in array 

#include <bits/stdc++.h>
using namespace std;



void insert(int a[],int n){
	int temp = a[n];
	int i = n;
	while(temp> a[i/2] && i>1){
		swap(a[i],a[i/2]);
		i = i/2;
	}
}
//faster method to create heap -- time complexity : O(n)
void heapify(int a[],int n,int i){

	
	int largest = i;
	int l = 2*i;
	int r=2*i+1;

	if(l<n && a[l]>a[largest]){
		largest=l;
	}
	if(r<n && a[r]>a[largest]){
		largest=r;
	}

	if(largest!=i){
		swap(a[i],a[largest]);
		heapify(a,n,largest);
	}

	return;

}

void delete_from_heap(int a[],int n){
	int x = a[1];
	a[1] = a[n-1];
	int i = 1;
	int j = 2*i;

	while(j<n-1){
		if(a[j]<a[j+1]){
			j++;
		}

		if(a[j]>a[i]){
			swap(a[i],a[j]);
			i=j;
			j = 2*j;
		}
		else 
			break;
	}

	a[n-1] = x;
}

//create heap method using insert function
//assume first element is already heap than insert the rest
//time complexity : O(n*logn) //logn for every element insert , n elements
void createheap(int a[],int n){
	for(int i=2;i<n;i++){
		insert(a,i);
	}
}

//heapsort using heapify only
void heapSort(int a[],int n){
	for(int i=n/2-1;i>=1;i--)
		heapify(a,n,i);

	for(int i=n-1;i>=1;i--){
		swap(a[1],a[i]);
		heapify(a,i,1);
	}
}


int main(){

	int h[] = {0,2,8,1,5,4,3,9,7};
	int p[] = {0,3,4,7,2,1,5,76,13};
	int n = sizeof(h)/sizeof(h[0]);
	int m = sizeof(p)/sizeof(p[0]);
	
	//createheap(h,n);

	//create heap using heapiy
	for (int i = n / 2 - 1; i >= 1; i--)
		heapify(h,n,i);

	//--heap sort-- is happening here, 
	//after creating heap
	//deleting elements one by one
	for(int i=n;i>1;i--){
		delete_from_heap(h,i);
	}

	
	heapSort(p,m);
	for(int i=1;i<n;i++){
		cout<<p[i]<<" ";
	}

	return 0;
}