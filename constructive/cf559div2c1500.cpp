//own
                                                C. The Party and Sweets

 n boys and m girls came to the party. Each boy presented each girl some integer number of sweets (possibly zero). All boys are 
numbered with integers from 1 to n and all girls are numbered with integers from 1 to m. For all 1≤i≤n the minimal number of sweets, 
which i-th boy presented to some girl is equal to bi and for all 1≤j≤m the maximal number of sweets, which j-th girl received from some
 boy is equal to gj.

More formally, let a(i,j) be the number of sweets which the i-th boy give to the j-th girl. Then bi is equal exactly to the
 minimum among values ai,1,ai,2,…,ai,m and gj is equal exactly to the maximum among values b(1,j),b(2,j),…,b(n,j).

You are interested in the minimum total number of sweets that boys could present, so you need to minimize the sum of a(i,j) for all (i,j) 
such that 1≤i≤n and 1≤j≤m. You are given the numbers b1,…,bn and g1,…,gm, determine this number.

Input
The first line contains two integers n and m, separated with space — the number of boys and girls, respectively (2≤n,m≤100000). 
The second line contains n integers b[1],…,b[n], separated by spaces — b[i] is equal to the minimal number of sweets, which i-th boy 
presented to some girl (0≤bi≤108). 
The third line contains m integers g[1],…,g[m], separated by spaces — g[j] is equal to the maximal 
number of sweets, which j-th girl received from some boy (0≤gj≤108).

Output
If the described situation is impossible, print −1. In another case, 
print the minimal total number of sweets, which boys could have presented and all conditions could have satisfied.

Examples
input
3 2
1 2 1
3 4
output
12
input
2 2
0 1
1 0
output
-1
input
2 3
1 0
1 1 2
output
4
solution:
 
 /* The idea here is that if the boyi gave b[i] number of sweets for some girl then for all other girls he would have given 
     atleast  b[i] sweets.and also if any g[i]<max(b[0]..b[n-1]) then we can't find the distribution.
 */
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
	int prime[100001];
	long long myceil(long long a,long long b)
	{
	   return (a+b-1)/b;
	}

	int main()
	{
	  int t=1;
	  //cin >> t;
	  while(t--)
	  {
	      long long n,m;
	      cin >> n >> m;
	      long long give[n],received[m];
	      for(int i=0;i<n;i++)
	         cin >> give[i];
	       for(int i=0;i<m;i++)
	         cin >> received[i];
	       long long max_given=*max_element(give,give+n);
	       int ans=false;
	       for(int i=0;i<m;i++)
	        if(received[i]<max_given){ans=true;break;}
	      if(ans)
	      {cout << "-1" << endl;continue;}
	      long long total=0;
	      for(int i=0;i<n;i++)
	        total+=give[i]*m; // as for every girl the ith boy is given give[i] sweets.
	      dbg(total);
	      sort(received,received+m,greater<int>());

	      for(int i=0;i<m-1;i++)
	       {
	           if(received[i]>max_given)total+=received[i]-max_given; 
	          /* If the received sweets is greater than max given then we 
	             have to give more received[i]-max_given sweets and increment the total by this much.
	             and also this is for only m-1 girls because if we do it for mth girl also then minsweets the ith boy is giving 
	             will be changed.
	          */
	       }
	       dbg(total);
	       sort(give,give+n,greater<int>());
	       if(received[m-1]>give[0])total+=received[m-1]-give[1]; // we should take the second biggest give[i].
	       cout << total << endl;
	  }
	  

	    
	  return 0;
	}
	   