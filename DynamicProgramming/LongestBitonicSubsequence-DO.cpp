#include <bits/stdc++.h>
using namespace std;

int LongestBitonicSequence(vector<int>nums)
{
    // code here
    int n = nums.size();
    
    int ldp[n+1],rdp[n+1];
    
    for(int i=0;i<=n;i++)
    {
        ldp[i]=1;
        rdp[i]=1;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(nums[i-1]<nums[j-1])
            {
                ldp[j]=max(ldp[j],1+ldp[i]);
            }
        }
    }
    
    for(int i=n;i>=1;i--)
    {
        for(int j=i-1;j>=1;j--)
        {
            if(nums[i-1]<nums[j-1])
            {
                rdp[j]=max(rdp[j],1+rdp[i]);
            }
        }
    }
    int val=0,mval=0;
    
    for(int i=1;i<=n;i++)
    {
        val = ldp[i]+rdp[i]-1;
        if(val>mval)
            mval = val;
    }
    
    return mval;
    
}

int main()
{
    vector<int> nums={1, 11, 2, 10, 4, 5, 2, 1};
    cout<<LongestBitonicSequence(nums)<<endl;
    return 0;
}