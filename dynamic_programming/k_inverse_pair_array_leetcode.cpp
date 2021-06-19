/*
                                            K Inverse Pairs Array

For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].

Given two integers n and k, return the number of different arrays consist of numbers from 1 to n such that there

are exactly k inverse pairs. Since the answer can be huge, return it modulo 10^9 + 7.

Example 1:

Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.
Example 2:

Input: n = 3, k = 1
Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
 
Constraints:

1 <= n <= 1000
0 <= k <= 1000
*/
// solution:
/*
Idea: if we know the number of inverse pairs(say x) in any arbitrary array b with some n, we can add a new 
element n+1 to this array b at a position p steps from the right, such that x+p=k to generate an array 
with a total of k inverse pairs.

Extending this idea further, suppose we know the number of arrangements of an array with n−1 elements, with the
number of inverse pairs being 0,1,2,...,k, let's say being equal to count_0, count_1, count_2,.., count_k 
Now, we can determine the number of arrangements of an array with n elements with exactly k inverse pairs easily

To generate the arrangements with exactly k inverse pairs and n elements, we can add the new number n to all the
arrangements with k inverse pairs at the last position. For the arrangements with k-1 inverse pairs , we can 
add n at a position 1 step from the right.

Similarly, for an element with k-i number of inverse pairs, we can add this new number n at a position i 
steps from the right. Each of these updations to the arrays leads to a new arrangement, each with the number of 
inverse pairs being equal to k.

Let's say count(i,j) represents the number of arrangements with ii elements and exactly j inverse pairs.

1) If n=0, no inverse pairs exist. 
Thus, count(0,k) = 0.

2) If k=0, only one arrangement is possible, which is all numbers sorted in ascending order. 
Thus, count(n,0) = 1.

3) Otherwise, count(n,k) = ∑ count(n-1, k-i) i=0 to min(n-1,k).

To solve the given problem, we make use of a 2-D dpdp, where dp[i][j] is used to store the number of
arrangements with ii elements and exactly jj inverse pairs.
*/
/*
From the last approach, we've observed that we need to traverse back to some limit in the previous row of the dp
array to fill in the current dp entry. Instead of doing this traversal to find the sum of the required elements,
we can ease the process if we fill the cumulative sum upto the current element in a row in any dp entry, instead
of the actual value.

Thus, now, dp[i][j] = count(i,j) + ∑ dp[i][k] where k = 0...j-1 

Here, count(i,j) refers to the number of arrangements with i elements and exactly j inverse pairs.
Thus, each entry contains the sum of all the previous elements in the same row along with its own result.

Now, we need to determine the value of count(i,j) to be added to the sum of previous elements in a row, in order 
to update the dp[i][j] entry. But, we need not traverse back in the previous row , since it contains entries 
representing the cumulative sums now. Thus, to obtain the sum of elements from 
dp[i−1][j−i+1] to dp[i−1][j](including both), we can directly use  dp[i−1][j]−dp[i−1][j−i]

we need to return dp[n][k]−dp[n][k−1] to obtain the required result from the cumulative sums.
*/
class Solution {
public:
    int mod = 1000000007;
    int kInversePairs(int n, int k) 
    {
        vector<vector<long long>> dp(n+1,vector<long long>(k+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(j==0)
                    dp[i][j] = 1;
                else if(i==0)
                    continue;
                else
                {
                    long long val = (j>=i)?dp[i-1][j-i]:0;
                    dp[i][j] = dp[i-1][j] + dp[i][j-1] - val;
                    dp[i][j] = (dp[i][j]+mod)%mod;
                }
            }
        }
        long long ans =  dp[n][k]-(k>0?dp[n][k-1]:0);
        ans+=mod;
        ans%=mod;
        return ans;
    }
};