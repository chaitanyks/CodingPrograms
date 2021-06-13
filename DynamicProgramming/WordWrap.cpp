//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int cost = nums[0];
        int mcost = 0;
        int ind = 1;
        while(ind<nums.size())
        {
            
            while(ind<nums.size() && cost+nums[ind]+1<=k)
            {
                cost = cost + nums[ind] + 1;
                ind=ind+1;
                
            }
            // cout<<ind<<" "<<cost<<endl;
            mcost = mcost + k-cost;
            cost = nums[ind];
            ind++;
            // cout<<ind<<" "<<mcost<<endl;
        }
        return mcost;
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends