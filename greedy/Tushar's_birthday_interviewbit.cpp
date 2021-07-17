/* 
                                         Tushar's Birthday Bombs

It’s Tushar’s birthday today and he has N friends.Friends are numbered [0, 1, 2, ...., N-1] and ith friend have a positive strength B[i].
Today being his birthday, his friends have planned to give him birthday bombs (kicks).
Tushar's friends know Tushar's pain bearing limit and would hit accordingly.
If Tushar’s resistance is denoted by A (>=0) then find the lexicographically smallest order of friends to kick 
Tushar so that the cumulative kick strength (sum of the strengths of friends who kicks) doesn’t exceed his 
resistance capacity and total no. of kicks hit are maximum.
Also note that each friend can kick unlimited number of times (If a friend hits x times, his strength will be counted x times)
Return the lexicographically smallest array of maximum length where the ith index represents the index of the friend who will hit.

NOTE:
[a1, a2, ...., am] is lexicographically smaller than [b1, b2, .., bm] if a1 < b1 or (a1 = b1 and a2 < b2) ...
Input cases are such that the length of the answer does not exceed 100000.

Problem Constraints
1 <= N <= 100
1 <= A <= 15 * 106
1 <= B[i] <= 105
Example Input
Input 1:
 A = 12
 B = [3, 4]
Input 2:
 A = 11
 B = [6, 8, 5, 4, 7]
Example Output
Output 1:
 [0, 0, 0, 0]
Output 2:
 [0, 2]
*/

//solution:
/*
    It is obvious that –> Maximum no. of kicks = R/(S[F]).
    This is the length of the answer but since we need lexicographically smaller order (according to index), 
    friends whose index is less than the F can also hit provided they do not change the length of the answer. 
    There is also a crucial observation here, we need not consider the friend which have a friend to their left 
    (lesser index) and have lesser than or equal strength than him. (Otherwise we can just take that friend with 
    lesser index instead).
*/
vector<int> solve(int A, vector<int> &B) 
{
    vector<int> ans(0);
    int max_len = 0;
    int mini = INT_MAX;
    for(int i=0;i<B.size();i++)
    {
      max_len = max(max_len,A/B[i]);
      mini = min(mini,B[i]);
    }
    for(int i=0;i<B.size();i++)
    {
        if(B[i]>A)continue;
        while(max_len>0 && A-B[i]>=(max_len-1)*mini)
        {
            A-=B[i];
            max_len--;
            ans.push_back(i);
        }
    }
    return ans;
}
