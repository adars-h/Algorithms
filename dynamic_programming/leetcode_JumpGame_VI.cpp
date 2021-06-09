/*	                                  
                                      1696. Jump Game VI

                        You are given a 0-indexed integer array nums and an integer k.
You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the 
boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.
You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you 
visited in the array.

Return the maximum score you can get.

Input: nums = [1,-1,-2,4,-7,3], k = 2
Output: 7
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.

Input: nums = [10,-5,-2,4,0,3], k = 3
Output: 17
Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.

*/

// solution:
/*

 Here we can use dp where dp[i] represents the maximum score we can get if we start at 0 and end at i.
 and dp[i] = nums[i]+max(dp[i-1],dp[i-2],...dp[i-k]), and if we iterate on i and for every i if we iterate backwards
 to find max among previous k states from i the Time Complexity will be O(n*k). Instead we can store only the previous 
 k states in multiset and we can now have max among previous states at last_element of multiset and we can retrieve it
 in O(log(k)) time and if our multiset reached size > k we can delete dp[i-k] element from multiset.

*/

int maxResult(vector<int>& nums, int k) 
 {
        vector<int> dp(nums.size(),INT_MIN);
        if(nums.size()==1)return nums[0];
          dp[0] = nums[0];
          multiset<int> s;
          s.insert(dp[0]); 
        for(int i=1;i<nums.size();i++)
        {
            auto it = s.end();
            it--;
            dp[i] = nums[i]+*it; // our max among (dp[i-1],dp[i-2],...dp[i-k]) will be last_element of multiset
            s.insert(dp[i]);  // we insert current dp[i] into multiset as it can be max for upcoming i+1,i+2..states
            if(s.size()>k) // if the multiset size > k that means we have included i-k-1,i-k-2.. states which we don't need.
            {
                auto it1 = s.find(dp[i-k]);
                s.erase(it1); // we erase those states as they no longer needed.
            }
        }
         return dp[nums.size()-1]; // return dp[n] 
 }
 // Further reading: There is also a O(n) solution to this problem where we have to deque instead of multiset.
 // O(n) solution: https://leetcode.com/problems/jump-game-vi/discuss/978462/C%2B%2B-DP-%2B-Monoqueue-O(n)