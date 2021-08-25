#include <iostream>

using namespace  std;

void swap(int* a, int* b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void selectionsort(int arr[], int n){
  for(int i =0;i < n; i++){
    for(int j=i+1;j<n;j++){
      if(arr[j]<arr[i]){
        swap(arr[i],arr[j]);
      }
    }
  }
}

void printarray(int arr[],int n){
  for(int i =0;i <n;i++){
    cout<<arr[i]<<" ";
  }
}


int main(){
  int n;
  cin>>n;

  int a[n];

  for(int i =0; i< n ; i++){
    cin>>a[i];
  }

  selectionsort(a,n);
  printarray(a,n);



  return 0;
}