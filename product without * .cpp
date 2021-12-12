#include <iostream>

using namespace std;

int prod(int a, int b) {
    if (b > a)
        swap(a, b);

    if (a == 0 || b == 0)
        return 0;
    if (a == 1)
        return b;
    if (b == 1)
        return a;

    int ta = a;
    if (b % 2 == 0) {
        a = a << 1;
        b = b >> 1;
        return prod(a, b);
    } else {
        a = a << 1;
        b = b >> 1;
        return ta + prod(a, b);
    }
}

int main() {
    // your code goes here
    for (int i = 0; i <= 10; i++) {
        cout << i * 6 << " " << prod(6, i) << endl;
    }
// 	cout<<prod(6,4)<<endl;
    return 0;
}
