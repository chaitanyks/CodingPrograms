#include<bits/stdc++.h>
using namespace std;

int knap01dp(int val[],int we[], int W,int n)
{
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 0;
    }
    for(int i=0;i<=W;i++)
    {
        dp[0][i] = 0;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(we[i-1]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i-1][j-we[i-1]]);
            }
        }
        // for(int k=0;k<=W;k++)
        // {
        //     cout<<dp[i][k]<<" ";
        // }
        // cout<<endl;
    }
    return dp[n][W];
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n=3;
    cout<<knap01dp(val,wt,W,n)<<endl;
}