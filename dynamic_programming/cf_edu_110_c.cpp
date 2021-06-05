 /*                                              C. Unstable String

		               You are given a string s consisting of the characters 0, 1, and ?.

				Let's call a string unstable if it consists of the characters 0 and 1 and any two adjacent 

				characters are different (i. e. it has the form 010101... or 101010...).

				Let's call a string beautiful if it consists of the characters 0, 1, and ?, and you can replace the 

				characters ? to 0 or 1 (for each character, the choice is independent), so that the string becomes unstable.

				For example, the strings 0??10, 0, and ??? are beautiful, and the strings 00 and ?1??1 are not.

				Calculate the number of beautiful contiguous substrings of the string s.

*/
//solution:
// This problem can be solved using dp where dp[i][j] represents no of substrings ending at i with last character as j.
// if current character is 0 then dp[i][0] = max(dp[i][0],1+dp[i-1][1])
// if current character is 1 then dp[i][1] = max(dp[i][1],1+dp[i-1][0])
// if current character is ? then dp[i][1] = max(dp[i][1],1+dp[i-1][0]) and dp[i][0] = max(dp[i][0],1+dp[i-1][1])
// at the end we need sum of all values of f(i) = max(dp[i][0],dp[i][1]) from i = 0 to n
int solve()
 {
 	string s;
    cin >> s;
    int n = s.size();
    int dp[n][2];
    memset(dp,0,sizeof(dp));
    if(s[0]!='1')
    {
      dp[0][0] = 1;
      dp[0][1] = 0;
    }
     if(s[0]!='0')
    {
      dp[0][0] = max(dp[0][0],0);
      dp[0][1] = 1;
    }
    for(int i=1;i<n;i++)
    {
       if(s[i]=='1')
       {
          dp[i][1] = max(dp[i][1],1+dp[i-1][0]);
       }
       if(s[i]=='0')
       {
         dp[i][0] = max(dp[i][0],1+dp[i-1][1]);
       }
       if(s[i]=='?')
       {
          dp[i][0] = max(dp[i][0],1+dp[i-1][1]);
          dp[i][1] = max(dp[i][1],1+dp[i-1][0]);
       }
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
       ans+=max(dp[i][1],dp[i][0]);
    }
    return ans; 
}