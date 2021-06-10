#include<bits/stdc++.h>
using namespace std;

int maxSumIS(int a[], int n)  
{  
    // Your code goes here
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i] = a[i-1];
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i-1]<a[j-1])
            {
                dp[j] = max(dp[j],a[j-1]+dp[i]);
            }
        }
    }
    return *max_element(dp,dp+n+1);
}

int main()
{
	int a[] = {44,47,32,22,26};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<maxSumIS(a,n)<<endl;
	return 0;
}