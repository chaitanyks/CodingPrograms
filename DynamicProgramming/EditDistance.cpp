#include<bits/stdc++.h>
using namespace std;

int editDistance(string s, string t, int n, int m)
{
    if(n==0)
        return m;
    if(m==0)
        return n;
        
    if(s[n-1] == t[m-1])
    {
        return editDistance(s,t,n-1,m-1);
    }
    else
    {
        return 1+min(editDistance(s,t,n-1,m-1),min(editDistance(s,t,n-1,m),editDistance(s,t,n,m-1)));
    }
}

int main()
{
	string s ="geek";
	string t ="ksdj";
	
	cout<<editDistance(s,t,s.length(),t.length())<<endl;
}