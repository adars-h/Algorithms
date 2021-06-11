/*                                
                                1690. Stone Game VII       

     Alice and Bob take turns playing a game, with Alice starting first.

    There are n stones arranged in a row. On each player's turn, they can remove either the leftmost stone or the

    rightmost stone from the row and receive points equal to the sum of the remaining stones' values in the row. 

    The winner is the one with the higher score when there are no stones left to remove.

    Bob found that he will always lose this game (poor Bob, he always loses), so he decided to minimize the score's 

    difference. Alice's goal is to maximize the difference in the score.

   Given an array of integers stones where stones[i] represents the value of the ith stone from the left, 

   return the difference in Alice and Bob's score if they both play optimally.

    Input: stones = [5,3,1,4,2]
    Output: 6
	Explanation: 
	- Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, stones = [5,3,1,4].
	- Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, stones = [3,1,4].
	- Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, stones = [1,4].
	- Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
	- Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
	The score difference is 18 - 12 = 6.

*/
// solution:
 int cache[1001][1001];
    int dp(int i,int j,vector<int>& stones,vector<int>& sum)
    {
        if(i<0 || j<0 || i>=stones.size() || j>=stones.size()) 
             return 0;
        if(i>=j)return 0;
        if(cache[i][j]!=-1)
             return cache[i][j];
        int take_j = sum[j] - sum[i] - dp(i,j-1,stones,sum);
        int take_i = sum[j+1] - sum[i+1] - dp(i+1,j,stones,sum);
        return cache[i][j] = max(take_j,take_i);
    }
    int stoneGameVII(vector<int>& stones) 
    {
        memset(cache,-1,sizeof cache);
        vector<int> sum(stones.size()+1);
        sum[0] = 0;
        for(int i=1;i<=stones.size();i++)
          sum[i] = sum[i-1]+stones[i-1];
       return dp(0,stones.size()-1,stones,sum);
    }