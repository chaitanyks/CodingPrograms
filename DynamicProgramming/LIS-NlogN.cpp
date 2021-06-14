#include <bits/stdc++.h>
using namespace std;
int nlogn(int a[], int n)
{
    vector<int> ans;
    ans.push_back(a[0]);
    int len=1;
    for(int i=1;i<n;i++)
    {
        if(ans[len-1]<a[i])
        {
            ans.push_back(a[i]);
            len++;
        }
        else
        {
            auto itr = upper_bound(ans.begin(),ans.end(),a[i]);
            ans[itr-ans.begin()]=a[i];
        }
    }
    return len;
}

int main() {
	// your code goes here
// 	int a[]={3,10,2,1,20};
// 	int a[] = {50, 3, 10, 7, 40, 80};
	int a[] = { 2, 5, 8, 7, 11, 8, 10, 13,6, 60, 68, 60, 69, 60 };
		
	int n = sizeof(a)/sizeof(a[0]);
	
	cout<<nlogn(a,n)<<endl;
	return 0;
    // This code is contributed by defcdr
}
