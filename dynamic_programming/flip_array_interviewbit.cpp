/*
                                                Flip Array
     Given an array of  positive elements, you have to flip the sign of some of its elements such that the resultant 
     sum of the elements of array should be minimum non-negative(as close to zero as possible). 
     Return the minimum no. of elements whose sign needs to be flipped such that the resultant sum is minimum 
     non-negative.

Constraints:

 1 <= n <= 100
Sum of all the elements will not exceed 10,000.

Example:

A = [15, 10, 6]
ans = 1 (Here, we will flip the sign of 15 and the resultant sum will be 1 )

A = [14, 10, 4]
ans = 1 (Here, we will flip the sign of 14 and the resultant sum will be 0)

Note that flipping the sign of 10 and 4 also gives the resultant sum 0 but flippings there are not minimum


    Idea: so the question asks us to find the minimum flips to made such that the sum is minimum.
    let's consider we have a,b,c,d,e,f as our elements and let S = a+b+c+d+e+f and S' be the sum when 
    some numbers in {a,b,c,d,e,f} are flipped. Now S' will look like S' = S-2*(sum_of_some_elements_in_S_flipped).
    Now, we want our S' to be as close to zero as possible so S'>=0 , S-2*(sum_of_some_elements_in_S_flipped)>=0.
    Therefore, we have sum_of_some_elements_in_S_flipped<=S/2, and this is a knapsack problem where we have knapsack
    of weight s/2 and we want minimum no of numbers who can fill the knapsack with masimum sum possible and less than
    s/2.
*/

// let dp[i] be the minumum no of numbers whose sum is as close to i as possible then our answer is dp[s/2].
int Solution(const vector<int> &A) 
{
    int sum = 0;
    for(auto it:A)
     sum+=it;
    sum/=2;
    vector<int> dp(sum+1,INT_MAX);
    dp[0] = 0;
    for(int i=0;i<A.size();i++)
    {
         for(int j=sum;j>=A[i];j--)
         {
              if(dp[j-A[i]]!=INT_MAX) // it means already there are some numbers whose sum is j-A[i] and they are minimum.
                    dp[j] = min(dp[j],dp[j-A[i]]+1);
         }
    }
    for(int j=sum;j>=0;j--)
      if(dp[j]!=INT_MAX) return dp[j];
       // given a set of numbers and k find minimum no of  numbers that sum upto k....
       //1 2 3 4 5 6 ......k
}

    