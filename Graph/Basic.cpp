#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
    cout << u << "------>" << v << endl;
}

void printEdge(vector<int> graph[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Edges for vertex " << i << endl;
        if (graph[i].size() == 0)
        {
            cout << "Vertex " << i << " is a Child Node" << endl;
        }
        else
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void countChild(vector<int> graph[], int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {

        if (graph[i].size() == 0)
        {
            count += 1;
        }
    }
    cout << "Child nodes count : " << count << endl;
}

int main()
{
    // your code goes here
    int N = 7;
    // 	cin>>N;
    vector<int> graph[N];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 5);
    addEdge(graph, 4, 6);
    printEdge(graph, N);
    countChild(graph, N);
    return 0;
}
