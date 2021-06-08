#include<bits/stdc++.h>
using namespace std;

int ncr(int n,int r)
{
	if(r>n)
		return 0;
		
	if(r == 0 || n == 0)
		return 1;
		
	return ncr(n-1,r-1)+ncr(n-1,r);
}

int main()
{
    int n = 778;
    int r = 4;
    
    cout<<nCr(n,r)<<endl;
}

// This code is contributed by defcdr