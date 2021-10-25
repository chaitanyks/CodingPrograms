
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
public:
    void topo(int V, vector<int> adj[], int index, bool visited[], vector<int> &ans, stack<int> &st) {
        if (visited[index] == false) {
            visited[index] = true;
            st.push(index);
            for (int i = 0; i < adj[index].size(); i++) {
                topo(V, adj, adj[index][i], visited, ans, st);
            }
            ans.push_back(index);
            st.pop();
        }
    }

    //Function to return list containing vertices in Topological order. 
    vector<int> topoSort(int V, vector<int> adj[]) {
        // code here
        int ind[V] = {0};

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                ind[adj[i][j]]++;
            }
        }


        bool visited[V] = {false};
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (ind[i] == 0)
                topo(V, adj, i, visited, ans, st);
        }

        for (int i = 0, j = ans.size() - 1; i < j; i++, j--) {
            int temp = ans[i];
            ans[i] = ans[j];
            ans[j] = temp;
        }
        return ans;
    }
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector<int> &res, vector<int> adj[]) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}  // } Driver Code Ends
