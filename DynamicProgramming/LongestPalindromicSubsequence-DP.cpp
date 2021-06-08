#include<bits/stdc++.h>
using namespace std;

int lpsdp(string s)
{
	int n = s.length();
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][i] = 1;
    }
    
    for(int Line = 2; Line <= n;Line++)
    {
        for(int i=1;i<=n-Line+1;i++)
        {
            int j=i+Line-1;
            
            if(s[i-1] == s[j-1] && Line==2)
            {
                dp[i][j] = 2;
            }
            else if(s[i-1] == s[j-1])
            {
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    return dp[1][n];
}

int main()
{
    string str = "GEEKSFORGEEKS";    
    cout<<lpsdp(str)<<endl;
}

// This code is contributed by defcdr