#include<bits/stdc++.h>

using namespace std;

int countSetBits(int A,int M)
{
    if(A==0)
        return 0;
    if(A%2==0)
    {
        int index = A/2;
        return (sol(index,M)%M+sol(index-1,M)%M+index%M)%M;
    }
    else
    {
        int index = (A-1)/2;
        return (2*sol(index,M)%M + index + 1)%M;
    }
}

int main()
{
  int A = 17;
  long long M = pow(10,9)+7;
  cout<<countSetBits(A,M)<<endl;
}
  

