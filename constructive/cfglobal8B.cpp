//own 
														B. Codeforces Subsequences
														
		Karl likes Codeforces and subsequences. He wants to find a string of lowercase English letters that contains at least k subsequences 
					"codeforces". Out of all possible strings, Karl wants to find a shortest one.

	Formally, a codeforces subsequence of a string s is a subset of ten characters of s that read codeforces from left to right. For
              example, the string codeforces contains "codeforces" a single time, while string codeforcesisawesome contains codeforces four times:
                         "codeforces"isawesome, "codeforce"si"s"awesome, "codeforce"sisaw"es"ome, "codeforce"sisawe"s"ome.

					Help Karl find any shortest string that contains at least k codeforces subsequences.

					Input
					The only line contains a single integer k (1≤k≤10^16).

					Output
					Print a shortest string of lowercase English letters that contains at least k codeforces subsequences. If 
					there are several such strings, print any of them.

					Examples

					input1
					1
					output1
					codeforces

					input2
					3
					output2
					codeforcesss
					solution:

				#include<bits/stdc++.h>
				#define fo(i,a,b)  for(int i=a; i<=b; i++)
				#define foi(i,a,b) for(int i=b-1; i>=a; i--)
				#define foo(i,n)   for(int i=0; i<n; i++)
				#define fooi(i,n)  for(int i=n-1; i>=0; i--)
				#define vii vector<int> 
				#define vll vector<long long>
				#define pii pair<int,int>
				#define vpii vector<pair<int,int>>
				#define vpll vector<pair<long long ,long long>>
				#define PB push_back
				#define DB pop_back
				#define MP make_pair
				#define F first
				#define S second
				#define mod 10000000001
				#define dbg(x) cerr<<#x<<" - "<<x<<endl;
				using namespace std;
				long long myceil(long long a,long long b)
				{
				   return (a+b-1)/b;
				}
				/* The main idea here is that if we have lets say instead of codeforces we have to form a string whose k subsequences to be form is abcd then 
				         if we have formed a string s then we can obtain na*nb*nc*nd no of subsequences where na is no of a's in the string s.
				            And for the length to be minimum we should adjust na,nb,nc,nd to almost equal like for ex :2,2,2,3 for 16<k<=24
				 */
				int main()
				{
				  int t=1;
				  //cin >> t;
				  while(t--)
				  {
				    long long  k;
				    cin >> k;
				    int arr[10];
				    string s="codeforces";
				    fill(arr,arr+10,1); // at first we must have all letters atleast one time.
				    long long product=1;
				    while(product<k)
				    {
				       for(int i=0;i<10;i++)
				       {
				          if(product>=k)break; // If the product is >= k then we know we can form atleast k subsequences of codeforces string so we have to break. 
				                              //   as  this is the minumum length we can achieve.
				          product/=arr[i];
				          arr[i]++;           // we increase the count of each letter and accordingly adjust the product
				          product*=arr[i];
				       }
				    }
				    for(int i=0;i<10;i++)
				    {
				       for(int j=0;j<arr[i];j++) // finally print resulting string.
				       {
				          cout << s[i];
				       }
				    }
				    cout << endl;
				  }
				  

				    
				  return 0;
				}