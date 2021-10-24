// C++ implementation of the approach
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<pair<int, int>> graph[], int u, int v, int w) {
    graph[u].push_back({v, w});
    // graph[v].push_back({u,w});
}

void printGraph(vector<pair<int, int>> graph[], int N) {
    for (int i = 0; i < N; i++) {
        cout << "index: :" << i << endl;
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j].first << " " << graph[i][j].second << endl;
        }
    }
}

bool bellmanFord(vector<pair<int, int>> graph[], int N, int index) {
    int dis[N];
    for (int i = 0; i < N; i++) {
        dis[i] = INT_MAX;
    }
    dis[index] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            dis[graph[i][j].first] = min(dis[graph[i][j].first], dis[i] + graph[i][j].second);
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int val = dis[graph[i][j].first];
            int val1 = dis[i] + graph[i][j].second;
            if (val > val1) {
                cout << "negative cycle detects : " << endl;
                return true;
            }
        }
    }


    for (int i = 0; i < N; i++) {
        cout << "Shortest path :" << i << " is " << dis[i] << endl;
    }
}


int main() {
    int N = 5;
    vector<pair<int, int>> adj[5];
    addEdge(adj, 0, 1, -1);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 3, 2);
    addEdge(adj, 1, 4, 2);
    addEdge(adj, 3, 2, 5);
    addEdge(adj, 3, 1, 1);
    addEdge(adj, 4, 3, -4);

    printGraph(adj, N);
    bellmanFord(adj, N, 0);

}
