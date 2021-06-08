#include<bits/stdc++.h>
using namespace std;

int lps(string s,int n,int i)
{
    if(i==n)
        return 1;
    if(i>n)
    {
        return 0;
    }
    
    if(s[i] == s[n] && n-i==1)
    {
        return 2;
    }
    
    if(s[i] == s[n])
    {
        return 2+pp(s,n-1,i+1);
    }
    else
    {
        return max(pp(s,n-1,i),pp(s,n,i+1));
    }
}

int main()
{
    string str = "GEEKSFORGEEKS";
    cout<<lps(str,str.length()-1,0)<<endl;
}

// This code is contributed by defcdr