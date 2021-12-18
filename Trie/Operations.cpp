#include <bits/stdc++.h>

using namespace std;

class Trie {
public:
    Trie *character[26];
    bool isEnd;

    Trie() {
        for (int i = 0; i < 26; i++) {
            this->character[i] = NULL;
        }
        this->isEnd = false;
    }

    void insert(string pattern) {
        int n = pattern.length();
        Trie *temp = this;
        for (int i = 0; i < n; i++) {
            int index = pattern[i] - 'a';
            if (temp->character[index] == NULL) {
                temp->character[index] = new Trie();
            }
            temp = temp->character[index];
        }

        temp->isEnd = true;
    }

    bool find(string str) {
        int n = str.length();
        Trie *temp = this;
        for (int i = 0; i < n; i++) {
            int index = str[i] - 'a';
            if (temp->character[index] == NULL) {
                return false;
            }
            temp = temp->character[index];
        }
        return temp->isEnd;
    }
};

int main() {
    // your code goes here
    Trie *root = new Trie();

    vector<string> str = {"asdfsaf", "sdfas", "sdfas", "abcd"};

    int n = str.size();
    for (int i = 0; i < n; i++) {
        root->insert(str[i]);
    }

    if (root->find("abcd")) {
        cout << "Yes" << endl;
    }
    
    if (root->find("abc")) {
        cout << "Yes" << endl;
    }

    return 0;
}
