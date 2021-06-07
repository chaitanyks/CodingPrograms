#include <iostream>
using namespace std;
int solve(string a,string b,int i,int j)
{
    if(i>=a.length())
    return 0;
    if(j>=b.length())
    return 0;
    
    int val = 0;
    int mval = 0;
    
    if(a[i] == b[j])
    {
        val = 1 + solve(a,b,i+1,j+1);
    }
    else
    {
        val = max(solve(a,b,i+1,j),solve(a,b,i,j+1));
    }
    
    if(val>mval)
        mval=val;
    return mval;
    
}

int main() {
	// your code goes here
	string a="ABCDGH";
	string b="AEDFHR";
	
	cout<<solve(a,b,0,0);
	return 0;
}
