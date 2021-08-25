//3 methods of finding maximum sub array
#include <iostream>
#include <climits>

using namespace  std;




int main(){
  int n;
  cin>>n;
  
  int maxsum = INT_MIN;

  int a[n];
  

  for(int i =0; i< n ; i++){
    cin>>a[i];
  }

  for(int i = 0; i < n ;i++){
    for(int j = i; j < n ; j++) 
    {
      int sum = 0;
        for(int k=i; k<=j;k++){
          sum += a[k];
          cout<<a[k];
        }
        maxsum = max(maxsum,sum);
        cout<<endl;
    }
    
    cout<<endl;
   }

   cout<<maxsum;


  return 0;
}