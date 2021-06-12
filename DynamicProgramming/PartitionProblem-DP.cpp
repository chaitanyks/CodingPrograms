#include<bits/stdc++.h>

using namespace std;

int equalPartitionDP(int n, int a[]) {
    // code here
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + a[i];
    }

    if (sum % 2 != 0)
        return 0;

    sum = sum / 2;
    int dp[n + 1][sum + 1];

    for (int i = 0; i <= sum; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (sum < a[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else if (j == a[i - 1]) {
                dp[i][j] = 1;
            } else {
                if (dp[i - 1][j - a[i - 1]] == 1 || dp[i - 1][j] == 1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        }
    }
    return dp[n][sum];
}

int main() {
    int arr[] = {2, 4, 11, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (equalPartitionDP(arr, n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}