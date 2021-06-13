bool check(struct val a,struct val b)
{
    if(a.first == b.first)
    return a.second<b.second;
    
    return a.first<b.first;
}

int maxChainLen(struct val p[],int n)
{
//Your code here
    int dp[n+1];
    sort(p,p+n,check);
    
    // for(int i=0;i<n;i++)
    // {
    //     cout<<p[i].first<<" "<<p[i].second<<"-";
    // }
    
    for(int i=0;i<=n;i++)
        dp[i] = 1;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            continue;
            if(p[j].first>p[i].second)
            {
                dp[j] = max(dp[j],1+dp[i]);
            }
        }
        // for(int k=0;k<=n;k++)
        // {
        //     cout<<dp[k]<<" ";
        // }
        // cout<<endl;
    }
    return *max_element(dp,dp+n);#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
bool check(struct val a,struct val b)
{
    if(a.first == b.first)
    return a.second<b.second;
    
    return a.first<b.first;
}

int maxChainLen(struct val p[],int n)
{
//Your code here
    int dp[n+1];
    sort(p,p+n,check);
    
    // for(int i=0;i<n;i++)
    // {
    //     cout<<p[i].first<<" "<<p[i].second<<"-";
    // }
    
    for(int i=0;i<=n;i++)
        dp[i] = 1;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            continue;
            if(p[j].first>p[i].second)
            {
                dp[j] = max(dp[j],1+dp[i]);
            }
        }
        // for(int k=0;k<=n;k++)
        // {
        //     cout<<dp[k]<<" ";
        // }
        // cout<<endl;
    }
    return *max_element(dp,dp+n);
}