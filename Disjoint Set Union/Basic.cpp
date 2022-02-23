#include <bits/stdc++.h>
using namespace std;

class DisjointSetUnion {
public:
    
    vector<int> parent;
    
    void makeSet(int n)
    {
        parent.resize(n);
        //make set 
        for(int i=0;i<n;i++)
        parent[i] = i;
    }
    
    int findSet(int a) {
        while(parent[a] != a) {
            parent[a] = parent[parent[a]];
            a = parent[a];
        }
        
        return a;
    }
    
    void unionSet(int a,int b)
    {
        int x = findSet(a);
        int y = findSet(b);
        if(x!=y)
            parent[x] = y;
    }
    
    void print(){
        for(auto i: parent)
            cout<<findSet(i)<<" ";
        cout<<endl;
    }
};

int main() {
    // your code goes here
    DisjointSetUnion disjointSetUnion;
    int n = 9;
    disjointSetUnion.makeSet(n);
    disjointSetUnion.unionSet(1,2);
    disjointSetUnion.unionSet(3,2);
    disjointSetUnion.unionSet(4,5);
    disjointSetUnion.unionSet(7,4);
    disjointSetUnion.unionSet(6,5);
    
    disjointSetUnion.print();
    return 0;
}
