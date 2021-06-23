/*
                     Find number of times a string occurs as a subsequence in given string

    Given two strings, find the number of times the second string occurs in the first string, 
    whether continuous or discontinuous.

Examples: 

Input:  
string a = "GeeksforGeeks"
string b = "Gks"

Output: 4
The four strings are - (Check characters marked in bold)
GeeksforGeeks
|  ||
GeeksforGeeks
|  |        |
GeeksforGeeks
|          ||
GeeksforGeeks
        |  ||
*/
// Idea
/*
    lets suppose the input provided is 3141592653 and the pattern sequence whose count to find is 123 . 
    I will begin by taking a hash map which maps characters in pattern to their positions in the 
    pattern . I also take an array of size M initially initialised to 0.I start looking for elements from the back and 
    check if each element is in the pattern or not . If that element is in the pattern i will do following.
    Now when i start looking from the back if i find a 2 and previously if i have not found any 3 . 
    This 2 is of no value to us.Because any 1 found after it will atmost form such sequence 12 and 123 wont be formed
    Also this 2 will form sequences 23 only if 3's found previously and will form x sequences if we found x 3's 
    previously .

    So the complete algorithm is whenever i find an element which is present in the pattern I check for its position j 
    correspondingly at which it was present in the pattern (stored in hash map). I just  increment
    arr[j] += arr[j+1];
    signifying it will contribute to sequences of 3 found before it.

    So finally , each index i in the array stores the number of times the substring of the pattern S[i,(m-1)] appers as 
    a subsequence of the given string. So finally print the value of arr[0].
*/

int count(string input,string pattern)
{
    int n = input.size();
    int m = pattern.size();
    int arr[m]; // stores the no of pattern(i,..m-1) subsequences in input.
    map<char,vector<int>> mp;// stores the indices of each character present in pattern.
    for(int i=0;i<m;i++)
    {
        mp[pattern[i]].push_back(i);
        arr[i] = 0;
    }

    for(int i =(n-1);i>= 0;i--)
    {
        char ch = input[i];
        if(mp.count(ch)) // if the character in input is present in pattern.
        {
    
            for(int k=0;k<mp[ch].size();k++)
            {
                int j = mp[ch][k];
                  if(j == (m-1))
                    { 
                        // if the index is last then just increment it as there is characters after that.
                      arr[j]++; 
                    }
                  else 
                    arr[j]+=arr[j+1];
                   
            }
        }
    }
    return arr[0];
    
}

        