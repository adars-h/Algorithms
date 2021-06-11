/*                                         
                                   F. Interesting Function

       You are given two integers l and r, where l<r. We will add 1 to l until the result is equal 

       r. Thus, there will be exactly r−l additions performed. For each such addition, let's look at the 

       number of digits that will be changed after it.

For example:

if l=909, then adding one will result in 910 and 2 digits will be changed;
if you add one to l=9, the result will be 10 and 2 digits will also be changed;
if you add one to l=489999, the result will be 490000 and 5 digits will be changed.
Changed digits always form a suffix of the result written in the decimal system.

Output the total number of changed digits, if you want to get r from l, adding 1 each time.

Input
The first line contains an integer t (1≤t≤104). Then t test cases follow.

Each test case is characterized by two integers l and r (1≤l<r≤109).

Output
For each test case, calculate the total number of changed digits if you want to get r from l, adding one each time.

input
4
1 9
9 10
10 20
1 1000000000
output
8
2
11
1111111110
*/
// solution 
/*
For each digit, we will count how many times it has changed.

The number of changes for the first digit (the lowest) is calculated using the formula r−l.

The number of changes for the second digit is calculated by the formula ⌊r/10⌋−⌊l/10⌋. 

That is, it is equivalent to the number of first-digit changes for numbers from ⌊l/10⌋ to ⌊r/10⌋.

To calculate the number of changes for the remaining digits, you need to apply similar reasoning 

with dividing the numbers by 10.

*/
	 int change_count(int l,int r)
	 {   
	 	int ans=0;
	     while(r>l)
	     {
	        ans+=(r-l);
	        r/=10;
	        l/=10;
	     }
	     return ans;
	 }
