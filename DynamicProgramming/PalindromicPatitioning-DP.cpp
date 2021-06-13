#include <bits/stdc++.h>
using namespace std;

int palindromicPartition(string str)
{
    // code here
    int n = str.length(), dp[n + 1][n + 1], c[n + 1], minv, val;

    memset(dp, false, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        minv = i;
        for (int j = 0; j <= i; j++)
        {
            if (str[i] == str[j] && (i - j <= 1 || dp[j + 1][i - 1]))
            {
                dp[j][i] = true;

                if (j == 0)
                    val = 0;
                else
                    val = c[j - 1] + 1;
                minv = min(minv, val);
            }
        }
        c[i] = minv;
    }
    return c[n - 1];
}

int main()
{
    // your code goes here
    string str = "ababbbabbababa";
    cout << dpsol(str1) << endl;
    return 0;
}