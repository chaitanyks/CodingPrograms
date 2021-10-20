
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> graph[], int u, int v) {
    graph[u].push_back(v);
}

void printGraph(vector<int> graph[], int V) {
    for (int i = 0; i < V; i++) {
        cout << "Vertex : " << i << endl;
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(vector<int> graph[], int V, int index) {
    bool visited[V] = {0};

    queue<int> q;
    q.push(index);
    while (!q.empty()) {

        if (visited[q.front()] == 0) {
            cout << q.front() << " ";
            int val = q.front();
            q.pop();
            for (int i = 0; i < graph[q.front()].size(); i++) {
                q.push(graph[val][i]);
            }
            visited[val] = 1;
        } else {
            q.pop();
        }
    }
}

void dfs(vector<int> graph[], int V, int index, bool visited[]) {
    if (visited[index] == 0) {
        visited[index] = 1;
        cout << index << " ";
        for (int i = 0; i < graph[index].size(); i++) {
            dfs(graph, V, graph[index][i], visited);
        }
    }
}

int main() {
    // your code goes here
    int V = 5;
    vector<int> graph[V];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printGraph(graph, V);
    bool visited[V] = {0};
    bfs(graph, V, 2);
    cout << endl;
    dfs(graph, V, 2, visited);
    return 0;
}

