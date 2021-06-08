#include<bits/stdc++.h>
using namespace std;

int knap01(int val[],int we[],int W,int n)
{
    if(n==0||W==0)
        return 0;
    if(we[n-1]>W)
        return knap01(val,we,W,n-1);
    else
    {
        return max(val[n-1]+knap01(val,we,W-we[n-1],n-1),knap01(val,we,W,n-1));
    }
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n=3;
    cout<<knap01(val,wt,W,n)<<endl;
}