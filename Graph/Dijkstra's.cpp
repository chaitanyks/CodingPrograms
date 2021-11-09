#include <bits/stdc++.h>

using namespace std;

void dijkstra(vector<pair<int, int>> graph[], int n, int start) {
    vector<long long> dist(n, INT_MAX);
    bool visited[n] = {false};
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    int count = 0;
    while (!pq.empty()) {
        int from = pq.top().second;
        pq.pop();
        if (visited[from])
            continue;
        visited[from] = true;
        for (int i = 0; i < graph[from].size(); i++) {
//            count++;
            int to = graph[from][i].first;
            int cost = graph[from][i].second;
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
                pq.push({-dist[to], to});
            }
//            cout<<count<<endl;
        }
    }

    for (int i = 1; i < n; i++) {
        cout << dist[i] << " ";
    }
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> graph[n + 1];
    while (m--) {
        // cout<<m<<endl;
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        // graph[v].push_back({u,w});
    }

    int start = 1;
    dijkstra(graph, n + 1, start);
    return 0;
}
