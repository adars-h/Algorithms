/*
                                            C. Little Alawn's Puzzle
When he's not training for IOI, Little Alawn enjoys playing with puzzles of various types to stimulate his brain.
Today, he's playing with a puzzle that consists of a 2×n grid where each row is a permutation of the numbers 1,2,3,…,n.
The goal of Little Alawn's puzzle is to make sure no numbers on the same column or row are the same (we'll call this
state of the puzzle as solved), and to achieve this he is able to swap the numbers in any column. However, after 
solving the puzzle many times, Little Alawn got bored and began wondering about the number of possible solved 
configurations of the puzzle he could achieve from an initial solved configuration only by swapping numbers in a 
column. Unfortunately, Little Alawn got stuck while trying to solve this harder problem, so he was wondering if 
you could help him with it. Find the answer modulo 109+7.
Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). Description of the test cases follows.
The first line of each test case contains a single integer n (2≤n≤4⋅105).
The next two lines of each test case describe the initial state of the puzzle grid. Each line will be a permutation of the numbers 1,2,3,…,n and the numbers in each column and row will be pairwise distinct.
It is guaranteed that the sum of n over all test cases does not exceed 4⋅105.
Output
For each test case output a single integer, the number of possible solved configurations of the puzzle Little Alawn can achieve from an initial solved configuration only by swapping numbers in a column. As the answer can be very large, please output it modulo 109+7.
The answer for each test case should be on a separate line. 
*/

// solution 

/*
 Let's say you know whether you flipped the first cell or not, which new columns must be flipped?
 Create a graph of n nodes, draw an edge between two values if they both exist in the same column, 
 what structure does this graph have? It is a bunch of disjoint cycles (since each node has an in-degree of 2).
 Each cycle is independent, and there are 2 ways to flip each cycle.
 
Define the "direction" of a column as the orientation of its numbers. Swapping the numbers in a column will flip 
its direction.Let's create a simple, undirected graph where the nodes are the n columns on the puzzle and we draw 
one edge connecting it to the 2 other columns that share a number with it. Notice that the degree of every node in 
this graph is 2, so the graph must be made of some number of disjoint simple cycles.Now consider any component in 
the graph. If we fix the direction of any of the columns in the component, that will fix the direction of the columns 
adjacent to it, and so on until the direction of every column in the component has been fixed (also note that as the 
component is a simple cycle, we will never get a contradiction). As there are 2 possible directions for any column,
there are thus 2 ways to direct the columns in this component.Lastly, notice that the columns in each component are
independent, so the answer is simply 2k, where k is the number of components in our graph.
Time Complexity: O(n) with DFS
*/
vector<vector<int>> arr;
vector<bool> vis;
map<int,int>& in_a;
void dfs(int idx,int flag,int node) // function that visits all nodes in a cycle...
{
     if(arr[flag][idx]==node) // base condition..
      return;
    vis[arr[flag][idx]] = true; 
    if(flag)
    {
      dfs(in_a[arr[flag][idx]],0,node);
    }
    else
    {
       dfs(idx,1,node);
    }
}
void t_c()
{
     int n;
     cin >> n;

     for(int i=0;i<2;i++)
      for(int j=0;j<n;j++)
         cin >> arr[i][j];

     for(int i=0;i<n;i++)
       in_a[arr[0][i]] = i; // mapping values in arr[0] to corresponding index 

     int cycles = 0;
     for(int i=0;i<n;i++) // counts cycles << endl;
     {
       if(!visited[arr[0][i]])
       {
         int node = arr[0][i];
         cycles++;
         visited[node] = true;
         dfs(i,1,node);
       }
     }
     cout << power(2,cycles) << endl;
}
