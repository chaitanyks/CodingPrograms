#include<bits/stdc++.h>
using namespace std;


void DFS(vector<int> graph[],vector<int> &low,vector<int> &disc,vector<bool> &visited,vector<int> &parent,bool isAP[],int time,int index) {
	time++;
	// cout<<time<<" "<<index<<endl;
	visited[index] = true;
	disc[index] = time;
	low[index] = time;
	int child = 0;
	for(int i=0;i<graph[index].size();i++)
	{
		child++;
		if(!visited[graph[index][i]])
		{
			parent[graph[index][i]] = index;
			DFS(graph,low,disc,visited,parent,isAP,time,graph[index][i]);
			low[index] = min(low[index],low[graph[index][i]]);

			if(parent[index] == -1 && child>=2)
				isAP[index] = true;

			if(parent[index]!=-1 && low[graph[index][i]]>=disc[index])
				isAP[index] = true;
		}
		else if(parent[index]!=graph[index][i])
		{
			low[index] = min(low[index],disc[graph[index][i]]);
		}
	}
}

void AP(vector<int> graph[],int v,int e)
{
	vector<int> low(v,INT_MAX);
	vector<int> disc(v,INT_MAX);
	vector<bool> visited(v,false);
	vector<int> parent(v);
	parent[0] = -1;
	bool isAP[v] = {false};
	DFS(graph,low,disc,visited,parent,isAP,0,0);

	for(int i=0;i<v;i++)
	{
		// cout<<low[i]<<" "<<disc[i]<<endl;
		if(isAP[i])
			cout<<i<<endl;
	}
}



int main(){
    int v,e;
	cin>>v>>e;
	vector<int> graph[v];
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	AP(graph,v,e);
}
