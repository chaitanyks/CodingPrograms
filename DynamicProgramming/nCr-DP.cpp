#include<bits/stdc++.h>
using namespace std;

int nCr(int n, int r)
{
        // code here
        int M = 1000000000+7;
        long long dp[n+1][r+1];
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i=1;i<=r;i++)
        {
            dp[0][i] = 0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=r;j++)
            {
                dp[i][j] = ((dp[i-1][j-1])%M + (dp[i-1][j])%M)%M;
            }
        }
        return dp[n][r];
}

int main()
{
    int n = 778;
    int r = 4;
    
    cout<<nCr(n,r)<<endl;
}

// This code is contributed by defcdr