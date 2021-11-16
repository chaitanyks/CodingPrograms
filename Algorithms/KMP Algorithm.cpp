// Write your code here
#include<bits/stdc++.h>

using namespace std;

void calLPS(vector<int>&lps, string pat) {
    int i = 1, len = 0;
    
    while (i < pat.length()) {
        if (pat[len] == pat[i]) {
            lps[i] = 1 + len;
            i++;
            len++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int kmp(string str, string pat) {
    int count=0,len=0,i=0;
    vector<int> lps(pat.length());
    lps[0] = 0;
    calLPS(lps, pat);
  
    while (i < str.length()) {
        if (str[i] == pat[len]) {
            i++;
            len++;
            if (len == pat.length()) {
                count++;
            }
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                i++;
            }
        }
    }
    return count;
}

int main() {
    string a, b;
    cin >> b >> a;
    cout << kmp(a, b) << endl;
}
