#include <bits/stdc++.h>
using namespace std;
int solve(int a[],int n, int i)
{
    if(i>=n)
        return 0;
    
    int val = 0;
    int mval = INT_MAX;
    
    for(int ind = i;ind<n;ind++)
    {
        val = solve(a,ind,i)+(a[ind]*a[i-1]*a[n])+solve(a,n,ind+1);
        if(val<mval)
        mval=val;
    }
    return mval;
}

int main() {
	// your code goes here
	int a[]={40, 20, 30, 10, 30} ;
	int n= sizeof(a)/sizeof(a[0]);
	cout<<solve(a,n-1,1)<<endl;
	return 0;
}
