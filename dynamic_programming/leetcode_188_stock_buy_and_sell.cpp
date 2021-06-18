/*                                      188. Best Time to Buy and Sell Stock IV

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. 
Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

*/
// solution:
int max_profit(vector<int>& prices,int k)
{
     // dp[i][j] is the profit I get if Iam at j th day and made i transactions..
     vector<vector<int>> dp(k+1,vector<int>(prices.size()+1));
     
     for(int i=0;i<=k;i++)
     {
          int maxi = -prices[0];//on buying on the first day our profit decreases by prices[0]
          for(int j=0;j<=prices.size();j++)
          {
             if(i==0 || j==0)
               continue;
               dp[i][j] = dp[i][j-1]; // Don't sell or buy on this day 
               dp[i][j] = max(dp[i][j],maxi+prices[j]); // sell on this day inorder to sell on this 
               // day we must have bought it on previous 1...j-1 days so we have to take 
               // max(-prices[k]+dp[i-1][k]) where k is 1...j-1. 
               maxi = max(maxi,dp[i-1][j]-prices[j]);// we should update the max inorder to use it in 
               // further days..
          }
     }
     return dp[k][prices.size()];
}