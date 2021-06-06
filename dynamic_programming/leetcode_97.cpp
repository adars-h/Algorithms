/*
                                                 97. Interleaving String

                        Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

                         An interleaving of two strings s and t is a configuration where they are divided into 

                                               non-empty substrings such that:

                                        s = s1 + s2 + ... + sn
                                        t = t1 + t2 + ... + tm
                                        |n - m| <= 1

            The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
            Note: a + b is the concatenation of strings a and b

            Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
            Output: true

            Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
            Output: false

            Input: s1 = "", s2 = "", s3 = ""
            Output: true
*/
// solution
/*
   The approach here is that in order to determine whether a substring of s3 (upto index k), 
   can be formed by interleaving strings s1 and s2 upto indices i and j respectively,  depends on the 
   characters of s1 and s2 upto indices i and j only and not on the characters coming afterwards.
*/
// let dp[i][j] be boolean value which states whether s3(1...(i+j)) can be formed from s1(1..i) and s2(1...j)
bool isInterleaving(string s1,string s2,string s3)
{
    if(s3.size()!= s1.size()+s2.size())
        return false;
    vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1));
    for(int i=0;i<=s1.size();i++)
    {
        for(int j=0;j<=s2.size();j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j] = true;
                continue;
            }
            else if(i==0)
            {
                dp[i][j] = (s2[j-1]==s3[i+j-1])? dp[i][j-1] : false;
                continue;
            }
            else if(j==0)
            {
                dp[i][j] = (s1[i-1]==s3[i+j-1])? dp[i-1][j]: false;
                continue;
            }
// if the last character in s1(0...i) is equal to last character in s3(0...i+j) then we need to consider dp[i-1][j]
            if(s1[i-1]==s3[i+j-1]) 
            dp[i][j] |= dp[i-1][j];
// if the last character in s2(0...j) is equal to last character in s3(0...i+j) then we need to consider dp[i][j-1].
           if(s2[j-1]==s3[i+j-1])
            dp[i][j] |= dp[i][j-1];
        }
         
    }
    return dp[s1.size()][s2.size()];
}