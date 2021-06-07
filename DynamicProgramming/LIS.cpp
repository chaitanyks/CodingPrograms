#include <iostream>
using namespace std;
int lis(int a[],int i, int n, int val)
{
    if(i>=n)
    return 0;
    
    int vul=0,mval=0;
    
    for(int ind=i;i<n;i++)
    {
        vul = lis(a,ind+1,n,a[ind]);
        
        if(a[ind]>val)
        {
            // vul = 1 + lis(a,ind+1,n,a[ind]);
            vul=vul+1;
        }
        
        if(vul>mval)
        mval=vul;
    }
    return mval;
    
}
int main() {
	// your code goes here
// 	int a[]={3,10,2,1,20};
	int a[] = {50, 3, 10, 7, 40, 80};
	int n = sizeof(a)/sizeof(a[0]);
	
	cout<<lis(a,0,n,a[0])+1<<endl;
	return 0;
}
