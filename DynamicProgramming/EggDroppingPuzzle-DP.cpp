#include<bits/stdc++.h>
using namespace std;
   
int eggdropdp(int n,int k)
{
    int dp[n+1][k+1];
    
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    
    for(int i=0;i<=k;i++)
    {
        dp[0][i]=0;
        dp[1][i]=i;
    }
    
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            dp[i][j]=INT_MAX;
            for(int ind=1;ind<=j;ind++)
            {
                int q = 1 + max(dp[i-1][ind-1],dp[i][j-ind]);
                if(q<dp[i][j])
                {
                    dp[i][j]=q;
                }
            }
        }
    }
    return dp[n][k];
}

int main()
{
    int n = 2;
    int k = 10;
    
    cout<<eggdropdp(n,k)<<endl;
}