//own
Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

solution:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0 || s.size()==1)
        	return s.size();
        int i=0,j=i+1;
/* The idea here is to use to pointers i and j and map the characters in the range [i-j] with their indices 
   and when moving j check if the map already contains the current character(s[j]), if it is present then
   first check if it's index(mapped value) is less than i and update else move the i pointer by that index+1 and 
   update the index of the current value and also keep updating the max length seen so far.
 */
        map<char,int> mp;
        mp[s[0]-'a']=0;
        int ans=1;
        while(j<s.size())
        {
            if(mp.count(s[j]-'a'))// checks if the current character already encountered
            {
                if(mp[s[j]-'a']<i) // if it is encountered before i update it.
                 {
                     mp[s[j]-'a']=j;
                     ans=max(ans,j-i+1);
                 }
                else{

                i=mp[s[j]-'a']+1; // update the current index.
                mp[s[j]-'a']=j;
                }
            }
            else
            {
                ans=max(ans,j-i+1);
                mp[s[j]-'a']=j;    // map the current index as it is not encountered
            }
            j++;
        }
        return ans;
    }
};