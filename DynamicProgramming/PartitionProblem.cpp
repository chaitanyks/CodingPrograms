#include <bits/stdc++.h>

using namespace std;

int pp(int a[], int n, int val, int sum) {
    if (n == 0)
        return 0;
    if (val == sum)
        return 1;
    return pp(a, n - 1, val + a[n - 1], sum) || pp(a, n - 1, val, sum);
}

int main() {
    int arr[] = {2, 4, 11, 10, 5};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    for (int i = 0; i < n1; i++) {
        sum = sum + arr[i];
    }
    if (sum % 2 == 0) {
        sum = sum / 2;
        if (pp(arr, n1, 0, sum))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}