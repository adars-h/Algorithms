/*                                 
                                            128. Longest Consecutive Sequence

                                       Given an unsorted array of integers nums, 

                               return the length of the longest consecutive elements sequence.

                                    You must write an algorithm that runs in O(n) time.

                                    Input: nums = [0,3,7,2,5,8,4,6,0,1]
                                    Output: 9

*/

// solution: 
 // The main idea here is to we have start with one number at index at i and start building longest sequence by incrementing it.
 // but if we already have a sequence that start with one minus number at index at i then we don't need to consider this number.

 int longestConsecutive(vector<int>& nums) 
 {
        unordered_set<int> s;
        for(auto it:nums) 
            s.insert(it); // put all numbers in a set.
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
        	 // if the sequence already exists with starting number as nums[i]-1 it is not optimal to consider 
             // the sequence that starts with current number.
            if(!s.count(nums[i]-1))
            {
                int number = nums[i];
                int length = 1;
                while(s.count(number+1))
                {
                    number++;length++;
                }
                ans = max(ans,length);
            }
        }
        return ans;
}