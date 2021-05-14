#include<bits/stdc++.h>
using namespace std;
int main()
{
	int vertices,edges;
	cin >> vertices >> edges;
	vector<int> adj[vertices];
	vector<int> indegree(vertices);
	for(int i=0;i<edges;i++)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		adj[a].push_back(b);
		indegree[b]++;
	}
	queue<int> q;
	int visited=0;
	for(int i=0;i<vertices;i++)
	{
	  if(indegree[i]==0)  // pushing the nodes which don't consist of incoming edges.
	  	q.push(i);
	}
	while(!q.empty())
	{
	   int node = q.front();
	   q.pop();
	   visited++;
	   for(int neighbour: adj[node])
	   {
	   	 indegree[neighbour]--;
	   	 if(indegree[neighbour]==0)
	   	 	q.push(neighbour);
	   }
	}
	/*
	   if visited!=vertices then there must be some vertices which
       forms a cycle and those vertices indegree never become zero.
    */
	if(visited==vertices) 
		cout << "No Cycle present" << endl;
	else
		cout << "There is a cycle" << endl;

}