#include<bits/stdc++.h>

using namespace std;

void zAlgo(string str, string pattern) {
    string newString = pattern + '$' + str;
    int zMap[newString.length()] = {0};
    int l = 0, r = 0;
    //create zMap
    for (int k = 1; k < newString.length(); k++) {
        if (k > r) {
            l = k;
            r = k;

            while (r < newString.length() && newString[r] == newString[r - l])
                r++;
            zMap[k] = r - l;
            r--;
        } else {
            int k1 = k - l;
            cout << k1 << endl;
            if (zMap[k1] < r - k + 1)
                zMap[k] = zMap[k1];
            else {
                l = k;
                while (r < newString.length() && newString[r] == newString[r - l])
                    r++;
                zMap[k] = r - l;
                r--;
            }
        }
    }

    //Check Zmap
    for (int i = 0; i < newString.length(); i++) {
        cout << zMap[i] << " ";
    }
}

int main() {
    string str = "aaaaabbaaaaaaabbaaaaaaaaa";
    string pattern = "aaaaa";
    zAlgo(str, pattern);
//    cout<<str.find(pattern)<<endl;
}
