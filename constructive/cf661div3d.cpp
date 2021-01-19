										D. Binary String To Subsequences

                      You are given a binary string s consisting of n zeros and ones.

  Your task is to divide the given string into the minimum number of subsequences in such a way that each character of the

        string belongs to exactly one subsequence and each subsequence looks like "010101 ..." or "101010 ..."

                    (i.e. the subsequence should not contain two adjacent zeros or ones).

             You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤2⋅10^4) — the number of test cases. 
Then t test cases follow.
The first line of the test case contains one integer n (1≤n≤2⋅10^5) — the length of s. 
The second line of the test case contains n characters '0' and '1' — the string s.

It is guaranteed that the sum of n does not exceed 2⋅10^5 (∑n≤2⋅10^5).

Output
For each test case, print the answer: in the first line print one integer k (1≤k≤n) — the minimum number of subsequences you can divide the string s to. In the second line print n integers a1,a2,…,an (1≤ai≤k), where ai is the number of subsequence the i-th character of s belongs to.

If there are several answers, you can print any.

Example
input
4
4
0011
6
111111
5
10101
8
01010000
output
2
1 2 2 1 
6
1 2 3 4 5 6 
1
1 1 1 1 1 
4
1 1 1 1 1 2 3 4 

solution:
#include<bits/stdc++.h>
#define dbg(x) cerr<<#x<<" - "<<x<<endl;
using namespace std;
int main()
{
  int t=1;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> one, zero;
    int num = 0;
    vector<int> ans(n);
    for(int i = 0; i < n; i++) 
    {
        if(S[i] == '0') 
        {
            if(zero.size())
             {
                auto idx = zero.back();
                zero.pop_back();
                ans[i] = idx;
                one.push_back(idx);
             } 
            else
             {
                num++;
                ans[i] = num;
                one.push_back(num);
            }
        }
        if(S[i] == '1') 
        {
           if(one.size()) 
            {
                auto idx = one.back();
                one.pop_back();
                ans[i] = idx;
                zero.push_back(idx);
            }
            else 
            {   
                num++;
                ans[i] = num;
                zero.push_back(num);
            }
        }
    }
    cout << num << endl;
    for(int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;
} 
  return 0;
}