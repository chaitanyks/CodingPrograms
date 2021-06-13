#include <bits/stdc++.h>
using namespace std;

bool checkP(string str, int i, int j)
{
    bool check = true;

    while (i <= j)
    {
        if (str[i] != str[j])
        {
            check = false;
        }
        i++;
        j--;
    }
    return check;
}

int pp(string str, int i, int n)
{
    if (i == n)
    {
        return 1;
    }

    if (i > n)
        return 0;

    int val = INT_MAX;
    int mval = INT_MAX;

    val = 1 + pp(str, i + 1, n);

    for (int j = i + 1; j <= n; j++)
    {
        if (checkP(str, i, j))
        {
            val = 1 + pp(str, j + 1, n);
        }

        if (val < mval)
        {
            mval = val;
        }
    }
    return mval;
}

int main()
{
    string str = "adfsfa";
    cout << pp(str, 0, str.length() - 1) -1 << endl;
    return 0;
}