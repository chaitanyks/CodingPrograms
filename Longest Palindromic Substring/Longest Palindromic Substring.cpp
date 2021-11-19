#include <iostream>

using namespace std;

void longestPalindromSubString(string str) {
    int n = str.length();
    int left = 0;
    int right = 0;
    int len = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++) {
        //odd
        left = i - 1;
        right = i + 1;
        while (left >= 0 && right < n && str[left] == str[right]) {
            left--;
            right++;

        }
        right--;
        left++;
        if (right - left + 1 > len) {
            len = right - left + 1;
            start = left;
            end = right;
        }

        // even
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && str[left] == str[right]) {
            left--;
            right++;
        }
        right--;
        left++;
        if (right - left + 1 > len) {
            len = right - left + 1;
            start = left;
            end = right;
        }
    }

    //print
    for (int i = start; i <= end; i++) {
        cout << str[i];
    }
}

int main() {
    // your code goes here
    string str = "aaaabbaabbaa";
    longestPalindromSubString(str);
    return 0;
}
