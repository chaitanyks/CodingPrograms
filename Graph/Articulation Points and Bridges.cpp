// Write your code here
#include<bits/stdc++.h>

using namespace std;


void DFS(vector<int> graph[], vector<int> &low, vector<int> &disc, vector<bool> &visited, vector<int> &parent, bool isAP[],
    int time, int index, vector<pair<int, int>> &edge) {
    time++;
    // cout<<time<<" "<<index<<endl;
    visited[index] = true;
    disc[index] = time;
    low[index] = time;
    int child = 0;
    for (int i = 0; i < graph[index].size(); i++) {
        if (!visited[graph[index][i]]) {
            child++;
            parent[graph[index][i]] = index;
            DFS(graph, low, disc, visited, parent, isAP, time, graph[index][i], edge);
            low[index] = min(low[index], low[graph[index][i]]);

            // Articulation Points
            if (parent[index] == -1 && child >= 2) {
                isAP[index] = true;
            }

            // Articulation Points
            if (parent[index] != -1 && low[graph[index][i]] >= disc[index])
                isAP[index] = true;

            //Bridge edge
            if (low[graph[index][i]] > disc[index])
                edge.push_back({index, graph[index][i]});

        } else if (parent[index] != graph[index][i]) {
            low[index] = min(low[index], disc[graph[index][i]]);
        }
    }
}

void AP(vector<int> graph[], int v, int e) {
    vector<int> low(v, INT_MAX);
    vector<int> disc(v, INT_MAX);
    vector<bool> visited(v, false);
    vector<int> parent(v);
    parent[0] = -1;
    bool isAP[v] = {false};
    vector<pair<int, int>> edge;
    DFS(graph, low, disc, visited, parent, isAP, 0, 0, edge);
    int count = 0;
    for (int i = 0; i < v; i++) {
        // cout<<low[i]<<" "<<disc[i]<<endl;
        if (isAP[i])
            count++;
    }

    cout << count << endl;
    for (int i = 0; i < v; i++) {
        // cout<<low[i]<<" "<<disc[i]<<endl;
        if (isAP[i])
            cout << i << " ";
    }
    cout << endl;
    cout << edge.size() << endl;
    sort(edge.begin(), edge.end());
    for (int i = 0; i < edge.size(); i++) {
        cout << edge[i].first << " " << edge[i].second << endl;
    }
	
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<int> graph[v];
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    AP(graph, v, e);
}
