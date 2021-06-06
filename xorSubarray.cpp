#include<bits/stdc++.h>
using namespace std;
int nox(vector<int> &a,int s)
{
    int ans=0,cv;
    map<int,int>mp;
    int n = a.size();
    int xc[n+1]={0};
    xc[0]=a[0];
    for(int i=1;i<n;i++)
    {
        xc[i]=xc[i-1]^a[i];
    }

    for(int i=0;i<n;i++)
    {
        cv = s^xc[i];
        if(xc[i]==s)
        {
            ans++;
        }
        ans = ans + mp[cv];
        mp[cv]++;
    }
    return ans;
}
int main()
{
    vector<int> a = {5,6,7,8,9};
    int n = sizeof (a)/sizeof(a[0]);
    int s=5;
    cout<<nox(a,s);
}