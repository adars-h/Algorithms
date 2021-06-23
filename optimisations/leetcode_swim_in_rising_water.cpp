/*
                                              Swim in Rising Water


                  On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another
 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can
  swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square 
(N-1, N-1)

*/
// The idea is to Use either Dijkstra's, or binary search for the best time T for which you can reach the end i
//f you only step on squares at most T.

//solution:
class Solution {
public:
// function to check if we are reachable from i,j with curr as T..
    bool possible(vector<vector<int>> & grid,int time,int i,int j,int curr,map<pair<int,int>,int>& mp)
    {
         if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]>time)
             return false;

         if(i==grid.size()-1 && j==grid[0].size()-1)
         {
            return (curr<=time);
         }   
       
        mp[{i,j}]++; // mark as visited
        int up = 0 , down = 0 ,left = 0, right = 0;
        if(i-1>=0 && !mp.count({i-1,j}))
        {
            int arg;
            if(grid[i][j]<=curr || grid[i-1][j]<=curr)
                arg = 0;
            else
                arg = grid[i-1][j]-curr;
            up = possible(grid,time,i-1,j,curr+arg,mp);
        }
        if(j-1>=0 && !mp.count({i,j-1}))
        {int arg;
            if(grid[i][j]<=curr || grid[i][j-1]<=curr)
                arg = 0;
            else
                arg = grid[i][j-1]-curr;
           left = possible(grid,time,i,j-1,curr+arg,mp);
        }
        if(j+1<grid[0].size() && !mp.count({i,j+1}))
        {int arg;
           if(grid[i][j]<=curr || grid[i][j+1]<=curr)
                arg = 0;
            else
                arg = grid[i][j+1]-curr;
           right = possible(grid,time,i,j+1,curr+arg,mp);
        }
        if(i+1<grid.size() && !mp.count({i+1,j}))
        {int arg;
            if(grid[i][j]<=curr || grid[i+1][j]<=curr)
                arg = 0;
            else
                arg = grid[i+1][j]-curr;
            down = possible(grid,time,i+1,j,curr+arg,mp);
        }
        return left || up || down || right;
    }
    int ans(vector<vector<int>>& grid,int low , int high)
    {
        int mini;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
             map<pair<int,int>,int> mp;
            // cout << mid << endl;
            if(possible(grid,mid,0,0,0,mp))
            {
                 
                mini = mid;
                high = mid-1;
            }
            else
              low = mid+1;
        }
        return mini;
    }
    int swimInWater(vector<vector<int>>& grid)
    {
        return ans(grid,0,1000000000);
    }
};

