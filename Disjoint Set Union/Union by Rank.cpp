#include <bits/stdc++.h>

using namespace std;

class DisjointSetUnion {
public:
    vector < int > parent;
    vector < int > rank;

    void makeSet(int n) {
        parent.resize(n);
        rank.resize(n);

        //make set 
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findSet(int a) {
        while (parent[a] != a) {
            parent[a] = parent[parent[a]];
            a = parent[a];
        }
        return a;
    }

    void unionSet(int a, int b) {
        int x = findSet(a);
        int y = findSet(b);

        if (x != y) {

            if (rank[x] < rank[y])
                swap(x, y);

            parent[y] = x;

            if (rank[x] == rank[y])
                rank[x]++;
        }
    }

    void print() {
        for (auto i: parent)
            cout << findSet(i) << " ";
        cout << endl;

        for (auto i: rank)
            cout << i << " ";
        cout << endl;
    }
};

int main() {
    // your code goes here
    DisjointSetUnion disjointSetUnion;
    int n = 9;
    disjointSetUnion.makeSet(n);
    disjointSetUnion.unionSet(1, 2);
    disjointSetUnion.unionSet(3, 2);
    disjointSetUnion.unionSet(4, 5);
    disjointSetUnion.unionSet(7, 4);
    disjointSetUnion.unionSet(6, 5);
    disjointSetUnion.unionSet(0, 8);
    disjointSetUnion.unionSet(4, 8);
    disjointSetUnion.unionSet(1, 8);

    disjointSetUnion.print();
    return 0;
}
