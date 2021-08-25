//sorting an array using recursion
//

#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &v,int num)
{
    if(v.size()==0 || v[v.size()-1]<=num)
    {
        v.push_back(num);
        return ;
    }
    int num2=v.back();
    v.pop_back();
    insert(v,num);
    v.push_back(num2);

}


void  sortv(vector<int> &v)
{
    if(v.size()==1)
    {
        return;
    }

    int num=v.back();
    v.pop_back();
    sortv(v);
    insert(v,num);

}

int main()
{
    vector<int> v={1,4,3,5,6,7,1,2,3};
    sortv(v);
    for (auto i : v) {
       cout<<i<<" ";
    }
}