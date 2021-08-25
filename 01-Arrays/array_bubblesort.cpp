#include <iostream>

using namespace  std;

void swap(int* a, int* b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void bubblesort(int arr[], int n){
  int c = 0;
  while(c<n){
    for(int j = 0; j <n-1-c;j++){
      if(arr[j]>arr[j+1])
      swap(arr[j],arr[j+1]);
    }
    c++;
    
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

  bubblesort(a,n);
  printarray(a,n);



  return 0;
}