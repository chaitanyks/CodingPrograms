#include<bits/stdc++.h>
using namespace std;

int ps(string str,int index,string curr)
{
    if(index==str.size())
    {
        cout<<curr<<endl;
        return 0;
    }
    ps(str,index+1,curr+str[index]);
    ps(str,index+1,curr)
}

int main()
{
    string str,curr;
    str="abcd";
    ps(str,0,curr);

}
