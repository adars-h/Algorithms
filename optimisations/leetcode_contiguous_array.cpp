                                                      525. Contiguous Array
                                                               Medium


						Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

						Example 1:
						Input: [0,1]
						Output: 2
						Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
						Example 2:
						Input: [0,1,0]
						Output: 2
						Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
						Note: The length of the given binary array will not exceed 50,000.


						solution:
						class Solution {

						/* 
							The idea here is if we have zeroes then we treat it as minus 1 and if we have a subarray which has 
							equal no of minus 1 and ones then sum of that sub array is 0. Thus when we calculate prefix sum of this 
							array lets say we have encountered x at j which we have already encountered at i then it means that the elements 
							from  i to j-1 sum to zero as that subarray has no contribution to prefixsum.
						*/
										public:
										    int findMaxLength(vector<int>& nums) {
										        int num=0;
										        for(int &x:nums)
										        x=(x==0)?-1:1;
										        map<int,int> mp;// map for storing the first distinct occurence of the prefixsum.
										        int ans=0;
										        mp[0]=-1; // to handle the case when at first we encounter the negative sum and then 0 and also  when the answer is nums.size().
										        for(int i=0;i<nums.size();i++)
										        {
										             num+=nums[i]; // we simply calculate the prefix sum.
										            if(mp.count(num)) // we check if its already encountered or not.
										            {
										                ans=max(ans,i-mp[num]); // as we want max size we caluclate it and update it .
										            }
										            else
										            {
										                mp[num]=i;
										            }
										        }
										        if(num==0)return (int)nums.size();
										        return ans;
										    }
						};