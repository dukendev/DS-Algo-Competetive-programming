#include <bits/stdc++.h>
using namespace std;

    vector<int> factorial(int N){
        // code here
        vector<int> res;
        res.push_back(1);
        int carry = 0;
        
        for(int i=2;i<=N;i++){
            for(int j=res.size() -1;j>=0;j--){
                int product = ((res[j]*i) + carry);
                carry = product/10;
                res[j] = product % 10;
            }   
            
            if(carry==0)
                continue;
                
            while(carry!=0){
                res.insert(res.begin(),carry%10);
                carry/=10;
            }
            
        }
        
        return res;
    }


    int main(){


        vector<int> s = factorial(5);
        for(int x: s){
            cout<<x;
        }

        return 0;
    }