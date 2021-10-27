#include<bits/stdc++.h>

using namespace std;

int root(int x, int parents[]) {
    while (parents[x] != x) {
        parents[x] = parents[parents[x]];
        x = parents[x];
    }
    return x;
}

void unionGraph(int x, int y, int parents[]) {
    parents[root(x, parents)] = parents[root(y, parents)];
}

int kruskalAlgo(pair<int, pair<int, int>> edge[], int parents[], int E) {
    int minCost = 0;
    for (int i = 0; i < E; i++) {
        int u = edge[i].second.first;
        int v = edge[i].second.second;
        int cost = edge[i].first;
        if (root(u, parents) != root(v, parents)) {
            minCost += cost;
            unionGraph(u, v, parents);
        }
    }
    return minCost;
}


int main() {

    int V = 5, E = 7;
    int parents[E];
    for (int i = 0; i < E; i++) {
        parents[i] = i;
    }
    pair<int, pair<int, int>> edge[E];
    edge[0] = make_pair(1, make_pair(0, 1));
    edge[1] = make_pair(7, make_pair(0, 2));
    edge[2] = make_pair(5, make_pair(1, 2));
    edge[3] = make_pair(3, make_pair(1, 4));
    edge[4] = make_pair(4, make_pair(1, 3));
    edge[5] = make_pair(6, make_pair(2, 4));
    edge[6] = make_pair(2, make_pair(3, 4));

    sort(edge, edge + E);

    for (int i = 0; i < E; i++) {
        cout << edge[i].first << " " << edge[i].second.first << " " << edge[i].second.second << endl;
    }

    cout << kruskalAlgo(edge, parents, E) << endl;
}
