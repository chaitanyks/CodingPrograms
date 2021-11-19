#include <bits/stdc++.h>

using namespace std;

void longestPalindromSubString(string str) {
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // create dp
    for (int indexi = 0; indexi < n; indexi++) {
        for (int indexj = 0; indexj < n - indexi; indexj++) {
            int i = indexj;
            int j = indexj + indexi;
            // cout<<i<<" "<<j<<endl;

            if (i == j)
                dp[i][j] = 1;
            else if (str[i] == str[j] && dp[i + 1][j - 1] == 1 || i + 1 == j) {
//                 cout << i << " " << j << endl;
                dp[i][j] = 1;
            }
        }
    }

    // find max
    int len = 0;
    int maxi = 0;
    int maxj = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
//             cout << dp[i][j] << " ";
            if (dp[i][j] == 1) {
                if (j - i > len) {
                    len = j - i;
                    maxi = i;
                    maxj = j;
                }
            }
        }
//         cout << endl;
    }



    //print
    for (int i = maxi; i <= maxj; i++) {
        cout << str[i];
    }
}

int main() {
    // your code goes here
    string str = "aaaabbaabbaa";
    longestPalindromSubString(str);
    return 0;
}
