#include <iostream>
using namespace std;

int solvedpnspace(string b,string a)
{
    int n=a.length();
    int m=b.length();
    int dp[m+1];
    for(int i=0;i<=m;i++)
    {
        dp[i]=0;
    }
    int old = 0;
    int dig = 0;
    
    for(int i=1;i<=n;i++)
    {
        dig = dp[0];
        for(int j=1;j<=m;j++)
        {
            old = dp[j];
            
            if(a[i-1]==b[j-1])
            {
                dp[j] = 1+dig;
            }
            else
            {
                dp[j] = max(dp[j],dp[j-1]);
            }
            dig = old;
        }
    }
    return dp[m];
}


int main() {
	// your code goes here
	string a="ABCD";
	string b="ABC";
	
	cout<<solvedpnspace(a,b);
	return 0;
}
