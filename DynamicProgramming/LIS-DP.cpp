#include <bits/stdc++.h>
using namespace std;
int lisdp(int a[], int n)
{
    int dp[n];
    
    for(int i=0;i<n;i++)
    {
        dp[i] = 1;
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
                dp[j]=max(dp[j],1+dp[i]);
        }
    }
    return *max_element(dp,dp+n);
}

int main() {
	// your code goes here
// 	int a[]={3,10,2,1,20};
	int a[] = {50, 3, 10, 7, 40, 80};
	int n = sizeof(a)/sizeof(a[0]);
	
	cout<<lisdp(a,n)<<endl;
	return 0;
    
// This code is contributed by defcdr
}
