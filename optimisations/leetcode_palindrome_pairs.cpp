/*
                                             336. Palindrome Pairs

         Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list,

         so that the concatenation of the two words words[i] + words[j] is a palindrome.

 

Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
Example 2:

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
Example 3:

Input: words = ["a",""]
Output: [[0,1],[1,0]]

*/

// solution:
/*

For each unique word in the words array, consider the word to be divided into two substrings, str1 and str2, with 
str1 progressively increasing from “” (empty) substring to the entire word while str2 assumes the remaining part of 
word. Check if str1 is a palindrome and if so then there is a possibility of it functioning as the pivot around which 
a palindrome could be formed. In order to determine whether a palindrome could be indeed formed, determine whether 
the reverse of the str2 exists within the map and does not correspond to the current index in contention 
(as is the case in case str2 is “aa” in which case reverse of str2 is also “aa” and hence can correspond to the 
current index in the map), so as to function as a prefix to form a palindrome with str1 as the pivot.

*/

/*

Now like wise check if str2 is a palindrome, in which case it can function as a pivot around which a palindrome can 
be formed. Check if the str1’s reverse is present in the map and does not correspond to the current index. Also in 
order to consider the corner case of “” empty string being one of the words in the array, there is a need to iterate 
until the length of word[i] inclusive. But this may lead to empty string “” being considered in str2 as a duplicate
in addition to being considered initially in str1. Therefore care must be taken to ensure that str2 is not equal 
to empty string to avoid duplicates.

 */
 vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        vector<vector<int>> pairs;
        map<string,int> mp;
        for(int i=0;i<words.size();i++)
            mp[words[i]] = i;
        if(mp.count(""))
        {
            for(int i=0;i<words.size();i++)
            {
                 if(words[i]=="")continue;
                 if(is_palindrome(words[i]))
                pairs.push_back({mp[""],i});
            }
        }
        for(int i=0;i<words.size();i++)
        { 
            
            for(int j=0;j<words[i].size();j++)
            {
                string str1 = words[i].substr(0,j);
                string str2 = words[i].substr(j);
                string str2rev = str2;
    
                reverse(str2rev.begin(),str2rev.end());
                
                if(is_palindrome(str1)  && mp.count(str2rev)  && mp[str2rev]!=i)
                {
                    pairs.push_back({mp[str2rev],i});
                  
                }
                string str1rev = str1;
                
                reverse(str1rev.begin(),str1rev.end());
                
                if(is_palindrome(str2)  && mp.count(str1rev) && mp[str1rev]!=i)
                {
                  pairs.push_back({i,mp[str1rev]});
                   
                }
            }
        }
        return pairs;
    }
    bool is_palindrome(string& s)
    {
        string temp = s;
        reverse(temp.begin(),temp.end());
        return (temp==s);
    }
