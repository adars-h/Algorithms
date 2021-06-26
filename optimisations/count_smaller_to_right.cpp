/*
                                Count of Smaller Numbers After Self

             You are given an integer array nums and you have to return a new counts array. 

The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104

*/
/*
Idea:the idea of the merge sort at the time of merging two arrays. 
When higher index element is less than the lower index element, it represents that the higher index element is 
smaller than all the elements after that lower index because the left part is already sorted. Hence add up to all 
the elements after the lower index element for the required count. 
*/
//solution:
class Solution {
public:
    void merge(vector<pair<int,int>>& arr,int low,int mid,int high,vector<int>& ans)
    {
        vector<pair<int,int>> left(mid-low+1),right(high-mid);
        int i=0,j=0;
        for(int k = low;k<=mid;k++)
             left[i++] = arr[k];
        for(int k=mid+1;k<=high;k++)
             right[j++] = arr[k];
        i=0;
        j=0;
        int k=low;
        while(i<left.size() && j<right.size())
        {
            if(left[i].first<=right[j].first)
            {
                ans[left[i].second]+=j; // add since upto j all elements are less than left[i].
                arr[k++] = left[i++];
            }
            else 
            {
                arr[k++] = right[j++];
            }
           
        }
        while(i<left.size())
        {
            ans[left[i].second]+=(j); // add elements in right array as they are less than left[i].
            arr[k++] = left[i++];
        }
        while(j<right.size())
           arr[k++] = right[j++];
    }
    void mergeSort(vector<pair<int,int>>& arr,int low,int high,vector<int>& ans)
    {
         if(low>=high)
              return;
         int mid = (low+high)/2;
         mergeSort(arr,low,mid,ans);
         mergeSort(arr,mid+1,high,ans);
         merge(arr,low,mid,high,ans);
    }
    vector<int> countSmaller(vector<int>& nums) 
    {
        vector<int> ans(nums.size());
        vector<pair<int,int>> arr(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            arr[i] = {nums[i],i}; // maintain the pair of index and value..
        }
        mergeSort(arr,0,arr.size()-1,ans);
        return ans;
    }
};