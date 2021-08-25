#include <iostream>
#include <climits>

using namespace std;


int main(){
  int A[] = {2,3,4,16,78,6,5};

  int n = sizeof(A)/sizeof(A[0]);

  int mx = INT_MIN;
  int mn = INT_MAX;

  for(int i = 0; i < n ; i++){
  
    mx = max(A[i],mx);
    
    mn = min(A[i],mn);
  }

  cout<<"Max is "<<mx<<endl;
  cout<<"Min is "<<mn;




  return 0;
}