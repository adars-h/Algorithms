/*
                                    Generate Parentheses

     Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 
Constraints:
1 <= n <= 8

*/
/*
   Idea is to use recursion for every pos in the array we can put '(' or ')' and if we reached the required length
   we check if it is valid or not. If it is valid then we add to the ans.
*/
class Solution {
public:
    bool valid(string& seq)
    {
        int balance = 0;
        for(auto it:seq)
        {
            if(it=='(')
                balance++;
            else
                balance--;
            if(balance<0)return false;
        }
        return balance==0;
    }
    void generate(string& seq,int pos,int n,vector<string>& ans)
    {
        if(pos==n)
        {
            if(valid(seq))
                ans.push_back(seq);
            return;
        }
        seq[pos] = '(';
        generate(seq,pos+1,n,ans);
        seq[pos] = ')';
        generate(seq,pos+1,n,ans);
    }
    vector<string> generateParenthesis(int n) 
    {
      vector<string> ans;
       string seq(2*n,' ');
         generate(seq,0,2*n,ans);
      return ans;
    }
};
// Time Complexity: O(2power(2n)) as the length is 2*n 
/* 
 We can optimize it further by placing closing brackets only when open>close and place open only when open < n
 This way we are maintaining the balance between opening and closing braces.
*/
class Solution {
public:
   
    void generate(string& seq,int pos,int n,vector<string>& ans,int open,int close)
    {
        if(pos==n)
        {
                ans.push_back(seq);
            return;
        }
        if(open<(n/2))
        {
            seq[pos] = '(';
            generate(seq,pos+1,n,ans,open+1,close);
        }
        if(close<open)
        {
            seq[pos] = ')';
            generate(seq,pos+1,n,ans,open,close+1);
        }
    }
    vector<string> generateParenthesis(int n) 
    {
      vector<string> ans;
       string seq(2*n,' ');
         generate(seq,0,2*n,ans,0,0);
      return ans;
    }
};