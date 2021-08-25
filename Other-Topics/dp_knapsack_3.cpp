//top down approach of dp
//knapsack problem 

#include <bits/stdc++.h>
using namespace std;


int knapSack(int W, int wt[], int val[], int n) 
    { 
       
       
       int t[n+1][W+1];
       int i,j;
       
        for(i=0;i<=n;i++){
            for(j=0;j<=W;j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
                
                else if(wt[i-1]<=j){
                        t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j]; 
                }
                    
            }
        }
          
       return t[n][W];
       
    }

int main(){

	int wt[] = {1,2,3,4,2};
	int val[] = {20,30,40,20,10};
	int n = 5;
	int w = 6;
	cout<<knapSack(w,wt,val,n);

	return 0;
}