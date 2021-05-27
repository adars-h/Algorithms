                                    318. Maximum Product of Word Lengths

            Given a string array words, return the maximum value of length(word[i]) * length(word[j])

              where the two words do not share common letters. If no such two words exist, return 0

       solution:
       /* 
        
         The main idea is to brute force for every {i,j} string pair but we have to optimise the cost of
         knowing whether two strings have atleast one same character or not. To do that we  have to use
         1111111... 26 bit representation  where the least significant bit corresponds to whether 'a' is
         present in the string or not.For ex: "abcef" has bit representation  110111. if the and of bit
         reprsentation numbers of two strings is zero that means they don't have even one character common.

       */
  class Solution
   {
      public:
    
      int maxProduct(vector<string>& words) 
      {
        int ans=0;
        int n = words.size();
        int check[n];
        for(int i=0;i<n;i++)
        {
             int num = 0;
            for(int j=0;j<words[i].size();j++)
            {
               int x = 1 << (words[i][j]-'a');
                num = num|x; 
            }
            // Now num contains the integer value of corresponding bit representation.
        
            check[i] = num;
            
         }
      
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if((check[i] & check[j])==0)
                    ans = max(ans,(int)(words[i].size())*(int)words[j].size());
            }
        }
        return ans;
    }
};