#include<bits/stdc++.h>
using namespace std;
int main()
{
   int vertices,edges;
   cin >> vertices >> edges;
   vector<int> adj[vertices];
   for(int i=0;i<edges;i++)
   {
   	 int a,b;
   	 cin >> a >> b;
   	 adj[a].push_back(b);
   	 adj[b].push_back(a);
   }
   
}