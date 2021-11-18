#include <bits/stdc++.h>

using namespace std;

void isprime(vector<bool> &is_prime, int n) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = pow(10, 7);
    vector<bool> is_prime(n + 1, true);
    isprime(is_prime, n);
    vector<int> left(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            left[i] = 1 + left[i - 1];
        } else
            left[i] = left[i - 1];
    }

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int total = m - n;
        int pv = left[m] - left[n + 1];
        total = total - pv;

        // for(int i=n+2;i<=m;i++)
        // {
        //     if(is_prime[i])
        //         total=total-1;
        // }
        cout << total << endl;
    }
    return 0;
}
