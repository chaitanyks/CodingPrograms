#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    double pi = 0;
    double odd = 1;
    for (int i = 0; i < 10000; i++) {
        if (i % 2 == 0)
            pi = pi + (1.0 / odd);
        else
            pi = pi - (1.0 / odd);
        odd = odd + 2;
        printf("%2.10000f\n",4*pi);
//        cout<<i<<" - " <<fixed<<setprecision(20)<<"Value of pi : "<<4*pi<<endl;
        // System.out.println("Value of pi : " + 4*pi);
//            System.out.printf("\n$%2.200f",pi);
    }
    return 0;
}
