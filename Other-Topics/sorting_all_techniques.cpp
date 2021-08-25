#include <bits/stdc++.h>
using namespace std;

void swap(int*x,int*y){
	int temp = *x;
	*x = *y;
	*y = temp;

	return;
}
//flag is added for making bubble sort adaptive
//if array is already sorted it will finish in one pass O(n)
void bubblesort(int a[],int n){
	int flag = 0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
				flag = 1;
			}
		}
		if(flag==0){
			break;
		}
	}
}

void insertionsort(int a[],int n){
	for(int i=1;i<n;i++){
		int j = i-1;
		int x = a[i];
		while(j>=0 && a[j]>x){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}
}
//this does more swaps
void selectionsort(int a[],int n){
	for(int i = 0 ; i < n-1; i++){
		for(int j = i +1; j<n;j++){
			if(a[j]<a[i]){
				swap(&a[j],&a[i]);
				cout<<"swap kia"<<endl;
			}
		}
	}
}
//this will only do O(n) swaps
void selectionsort2(int a[],int n){
	int i,j,k;
	for(i = 0;i < n-1;i++){
		for(j=k=i;j<n;j++){
			if(a[j]<a[k])
				k=j;
		}
		swap(&a[i],&a[k]);
		cout<<"swap kia"<<endl;
	}
}

int partion(int a[],int l,int r){
	int pivot = a[r];
	int i = l-1;
	for(int j=l;j<r;j++){
		if(a[j]<pivot){
			i++;
			swap(&a[i],&a[j]);
		}		
	}
	swap(&a[i+1],&a[r]);
	return i+1;
}

void quicksort(int a[],int l ,int r){
	if(l<r){
		int pi = partion(a,l,r);
		quicksort(a,l,pi-1);
		quicksort(a,pi+1,r);
	}
	return;
}

void merge(int a[],int l,int mid,int r){
	int n1 = mid-l+1;
	int n2 = r-mid;

	int t1[n1];
	int t2[n2];

	for(int i=0;i<n1;i++){
		t1[i] = a[l+i];
	}


	for(int i=0;i<n2;i++){
		t2[i] = a[mid+1+i];
	}

	int i=0;
	int j=0;
	int k=l;
	while(i<n1 && j<n2){
		if(t1[i]<t2[j]){
			a[k++] = t1[i++];
		}
		else
			a[k++] = t2[j++];

	}

	while(i<n1){
		a[k++] = t1[i++];
	}
	while(j<n2){
		a[k++] = t2[j++];
	}


}

void mergesort(int a[],int l,int r){
	if(l<r){
		int mid = (l+r)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}

int findmax(int a[],int n){
	int mx = INT_MIN;
	for(int i = 0 ; i < n ;i++){
		mx = max(mx,a[i]);
	}

	return mx;
}
void countsort(int a[],int n){

	int max = findmax(a,n);
	vector<int> c(max+1); 
	//vector will be initialized by default will zeros
	//vector<int> c(max+1,0);
	for(int i = 0;i<n;i++){
		c[a[i]]++;
	}

	int i=0,j=0;
	while(i<max+1){
		if(c[i]>0){
			a[j++] = i;
			c[i]--;
		}
		else
			i++;
	}
}

void printarray(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(){

	int a[] = {4,3,2,6,8,5};
	int n = 6;

	//bubblesort(a,n);
	//insertionsort(a,n);
	//selectionsort2(a,n);
	//quicksort(a,0,n-1);
	//mergesort(a,0,n-1);
	//countsort(a,n);
	printarray(a,n);
	return 0;
}