#include <iostream>
using namespace std;

struct pairs{
    int min;
    int max;
};

pairs find_min_max(int a[],int n){
    
    
    pairs data;
    int i;
    
    if(n%2==0){
        if(a[0]>a[1]){
            data.min = a[1];
            data.max = a[0];
        }
        else{
            data.min = a[0];
            data.max = a[1];
        }
        
        i = 2;
    }
    else{
        data.min = a[0];
        data.max = a[0];
        
        i = 1;
    }
    
    while(i<n-1){
        
        if(a[i]<a[i+1]){
            
            if(a[i]<data.min){
                data.min = a[i];
            }
            else if(a[i+1]>data.max){
                data.max = a[i+1];
            }
            
        }
        
        else{
            if(a[i+1]<data.min){
                data.min = a[i+1];
            }
            else if(a[i]>data.max){
                data.max = a[i];
            }
            
            }
        i+=2;
            
        }
        
        
        
        
    return data;
}

int main() {
	int arr[8] = {1,2,3,4,400,67,6,95};
  int n = sizeof(arr)/sizeof(arr[0]);
	pairs res;
	res = find_min_max(arr,n);
  cout<<res.min<<" "<<res.max;
	return 0;
}