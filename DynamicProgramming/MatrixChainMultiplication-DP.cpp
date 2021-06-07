#include <bits/stdc++.h>
using namespace std;

int dpsol(int a[], int n)
{
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][i] = 0;
    }
    
    for(int L = 2;L<=n;L++)
    {
        for(int i = 1;i<=n-L+1;i++)
        {
            int j=L+i-1;
            dp[i][j] = INT_MAX;
            for(int k = i;k<j;k++)
            {
                int q = dp[i][k] + dp[k+1][j] + a[k]*a[j]*a[i-1];
                if(q<dp[i][j])
                    dp[i][j] = q;
            }
        }
    }
    return dp[1][n];
}


int main() {
	// your code goes here
	int a[]={40, 20, 30, 10, 30} ;
	int n= sizeof(a)/sizeof(a[0]);
	cout<<dpsol(a,n-1)<<endl;
	return 0;
}
