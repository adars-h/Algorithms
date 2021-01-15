                    1718. Construct the Lexicographically Largest Valid Sequence

Given an integer n, find a sequence that satisfies all of the following:

1->The integer 1 occurs once in the sequence.
2->Each integer between 2 and n occurs twice in the sequence.
3->For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.

A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

 

Example 1:

Input: n = 3
Output: [3,1,2,3,2]
Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
Example 2:

Input: n = 5
Output: [5,3,1,4,3,5,2,4,2]
 

Constraints:

1 <= n <= 20
solution:

class Solution {
public:
    bool fill(vector<int> &nums,vector<bool> &used,int idx)
    {
        if(idx==nums.size())return true; // if the index which is to be filled is out of bound then we have filled the array so returns true.
        if(nums[idx])return fill(nums,used,idx+1); // if the current index is filled then we have to fill the next index.
        for(int num=used.size()-1;num>=0;num--) // we have to fill the largest number which is not used as to form lexicographically greater.
        {
             if(used[num])continue; 
             if(num!=1 && (idx+num>=nums.size()||nums[idx+num]))continue;// nums[idx+num] cannot be filled when idx+num is out of bound or it is already filled.
             used[num]=true;
            nums[idx]=num;                   // we have to set this and idx+num to num.
            if(num!=1)nums[idx+num]=num;
            if(fill(nums,used,idx+1))return true; // if the next index is filled correctly return current state of sequence.
            nums[idx]=0;  // else we try out next biggest number which is not used by resetting the current idx to 0.
            if(num!=1)nums[idx+num]=0;
            used[num]=false;
        }
        // if we exhausted all the numbers and still not formed a sequence return false.
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
      vector<int> nums(2*n-1,0); // Result array that has to be return.
      vector<bool> used(n+1,false); // utility array to keep track of the used numbers.
      if(n!=1)
      {
        nums[0]=n;
        nums[n]=n;        // initialising the first element.
          used[n]=true;
      }
        else nums[0]=1;
      bool ans=fill(nums,used,1); // call to fill the next index which is 1 and hence then whole indices.
        return nums;
    }
};