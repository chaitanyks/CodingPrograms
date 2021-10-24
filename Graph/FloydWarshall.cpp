#include <bits/stdc++.h>

#define INF 999
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v, int w) {
    adj[u][v] = w;
}

void warshal(vector<vector<int>> &adj, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (adj[i][k] == INF || adj[k][j] == INF)
                    continue;
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

void printY(vector<vector<int>> &adj, int N) {
    for (int i = 0; i < N; i++) {
        // vector<int> id;
        for (int j = 0; j < N; j++) {
            cout << adj[i][j] << " ";
        }
        // adj.push_back(id);
        cout << endl;
    }
}

int main() {
    int N = 4;
    vector<vector<int>> adj;
    for (int i = 0; i < N; i++) {
        vector<int> id;
        for (int j = 0; j < N; j++) {
            if (i == j)
                id.push_back(0);
            else
                id.push_back(INF);
        }
        adj.push_back(id);
    }
    // addEdge(adj, 0, 1, -1);
    // addEdge(adj, 0, 2, 4);
    // addEdge(adj, 1, 2, 3);
    // addEdge(adj, 1, 3, 2);
    // addEdge(adj, 1, 4, 2);
    // addEdge(adj, 3, 2, 5);
    // addEdge(adj, 3, 1, 1);
    // addEdge(adj, 4, 3, -2);
    addEdge(adj, 0, 3, 10);
    addEdge(adj, 0, 1, 5);
    addEdge(adj, 2, 3, 1);
    addEdge(adj, 1, 2, 3);

    warshal(adj, N);
    printY(adj, N);
    return 0;
}
