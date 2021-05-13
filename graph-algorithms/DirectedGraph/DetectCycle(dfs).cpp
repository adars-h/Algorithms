#include<bits/stdc++.h>
using namespace std;
bool has_cycle(int curr,vector<int>adj[],vector<int>&visited,vector<int>&inStack)
{
    if(!visited[curr])
    {
        visited[curr] = true;
        inStack[curr] = true;
        for(int neighbor: adj[curr])
        {
	        if(!visited[neighbor] && has_cycle(neighbor,adj,visited,inStack))
	            return true;
	        else if(inStack[neighbor]) //  the node has a backedge to the node which is in recusion stack.
	            return true;
        }
    }
     inStack[curr] = false;  // pop from the recursion stack.
        return false;
 }
int main()
{
   int vertices, edges;
   cin >> vertices >> edges; // input no of nodes and edges
   vector<int> adj[vertices];
   for(int i=0;i<edges;i++)
   {
   	 int a,b;
   	 cin >> a >> b;
   	 adj[a].push_back(b); // a has directed edge to b
   }
   vector<int> visited(vertices); // to keep track of visited nodes.
   vector<int> inStack(vertices); // to keep track of nodes in the recusion stack
   bool cycle = false;
   for(int vertex=0;vertex<vertices;vertex++)
    {
    	/* 
    	   Any vertex that has been marked as visited means that we’ve explored every
		   path from that vertex. Since we didn’t find a cycle, we can assume 
		   that when we come across a visited vertex, we can ignore it because we already know 
		   that it doesn’t have a cycle
		*/
       if(!visited[vertex]) 
        {
          cycle = has_cycle(vertex,adj,visited,inStack);
          if(cycle)
          break;
        }
    }
    cout << cycle << endl;
}