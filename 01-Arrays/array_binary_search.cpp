#include <iostream>

using namespace  std;

int BinarySearch(int arr[],int n,int key){
  int s =0;
  int e = n -1;
  while(s<=e){
    int m = (s+e)/2;
    if(key==arr[m])
    return m;
    else if(key<arr[m]){
      e = m -1;
    }
    else 
      s = m +1;
  }

  return -1;
}

int main(){
  int n;
  cin>>n;

  int a[n];

  for(int i =0; i< n ; i++){
    cin>>a[i];
  }

  int key;
  cout<<"enter search "<<endl;
  cin>>key;

  cout<<BinarySearch(a, n, key);

  return 0;
}