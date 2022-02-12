#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int minEdgeBFS(vector<int> edges[], int u, int v, int n) {
        vector<bool> visited (n, 0);
        int distance = 0;

        queue<pair<int, int>> q;

        q.push({u, 1});
        visited[u] = true;

        while (!q.empty()) {
            int x = q.front().first;
            int dis = q.front().second;
            q.pop();

            if (x == v) {
                distance = dis;
                break;
            }

            for (int i = 0; i < edges[x].size(); i++) {
                if (visited[edges[x][i]])
                    continue;

                q.push({edges[x][i], dis + 1});
                visited[edges[x][i]] = 1;
            }
        }
        return distance;
    }

int main()
{
    // your code goes here
    int N = 8;
    
    // 	  Graph
    //          0
    //        /   \ 
    //       /     \
    //     1        2
    //   / \ \     /
    //  3  4  5   /
    //    /    \ /
    //   6      7 
    
    vector<int> graph[N];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 7);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 7);
    
    cout<<"Min distance between 0 to 7: "<<minEdgeBFS(graph,0,7,N)<<endl;
    return 0;
}
