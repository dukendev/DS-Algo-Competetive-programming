#include <iostream>

using namespace  std;

void swap(int* a, int* b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void insertionsort(int arr[], int n){
  for(int i = 1;i <n;i++){
    int curr = arr[i];
    int j = i -1;
    while(arr[j]>curr && j>=0){
      arr[j+1] = arr[j];
      j--;

    }
    arr[j+1] = curr;

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

  insertionsort(a,n);
  printarray(a,n);



  return 0;
}