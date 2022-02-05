/*                                                        1248. Count Number of Nice Subarrays

            Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
            Return the number of nice sub-arrays.
            
            1) Using i iterate over the array counting only odd numbers.
            2) When odd is equal to k, we can analyse our left part and count how many subarrays with odd == k we can produce.
            3) Continue with i again. Since odd >= k then every next even number we meet is going to double previous count. 
              
              for ex: let's say we have 
              _ _ _ _ _
                _ _ _ _
                  _ _ _
              2 2 1 1 2 2 1 2
                  j   i
              _ _ _ _
                _ _ _
                  _ _
            4) When we meet odd number again we need to reset count=1 and repeat step (2) with j again. 
            5) And finish with counting last even number as in step (3).
*/ 
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int cnt = 0;
        int curr_odd = 0;
        int j = 0;
        int total = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2)
            {
                curr_odd++;
                if(curr_odd>=k)
                {
                    cnt = 1;
                    while(!(nums[j++]%2))
                        cnt++;
                    total+=cnt;
                }
            }
            else if(curr_odd>=k)
                 total+=cnt;
        }
        return total;
    }
};