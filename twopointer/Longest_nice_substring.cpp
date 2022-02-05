/*                                                   1763. Longest Nice Substring

           A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. 
           For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.
           Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest 
           occurrence. If there are none, return an empty string.


           Idea:

           The key observation here is that if a character doesn't have its other half (different case but same character) in the given 
           string, it can't be included into any of the nice substring.For instance, let's look at string "abcBCEAamM". We notice that 
           every alphabet has both cases present in the string except character E. So any nice string can't have E in it. In other words, 
           the longest nice substring must be either in E's left side or its right side, namely "abcBC" or "AamM". We notice that we just
           create 2 subproblems to find the longest nice substring in "abcBC" and "AamM".When we get result from solving left subproblem
           and right subproblem, we simply compare the length of two strings and return the one with longer length. Note that if both 
           strings have the same length, we need to return the left one since the problem statement explicitly mentions: If there are 
           multiple, return the substring of the earliest occurrence.Now what if we don't see any un-paired character after we go 
           through the string? That's good because that means the original string is a nice string, so we simply return it since it
           must be the longest one.
*/
class Solution 
{
    public:
    string longestNiceSubstring(string s) 
    {
        if(s.size()<2)
                return "";
        int cnt1[26] = {0};
        int cnt2[26] = {0};
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                if(cnt1[s[i]-'A']==1)
                    continue;
                else
                    cnt1[s[i]-'A']++;
            }
            else 
            {
                if(cnt2[s[i]-'a']==1)
                    continue;
                else
                    cnt2[s[i]-'a']++;
            }
        }
        int ans = 0;
        string res1,res2;
        int j = 0;
        for(int i=0;i<s.size();i++)
        {
            if(cnt1[toupper(s[i])-'A']+cnt2[tolower(s[i])-'a']<2)
            {
                res1= longestNiceSubstring(s.substr(0,i));
                res2= longestNiceSubstring(s.substr(i+1));
                if(res1.size()>=res2.size())
                    return res1;
                return res2;
            }
        }
        return s;
    }
};