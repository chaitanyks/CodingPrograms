#include<bits/stdc++.h>
using namespace std;

int eggdrop(int n,int k)
{
    if( n==1)
    {
        return k;
    }
    if(k == 0)
    {
        return 0;
    }
    int mval = INT_MAX;
    for(int i=1;i<=k;i++)
    {
        int val = 1 + max(eggdrop(n-1,i-1),eggdrop(n,k-i));
        if( val < mval )
        {
            mval = val;
        }
    }
    return mval;
}
    
int main()
{
    int n = 2;
    int k = 10;
    
    cout<<eggdrop(n,k)<<endl;
}