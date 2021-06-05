
                                          // Maximum Performance of a Team
/*

You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n engineers 
numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.

Choose at most k different engineers out of the n engineers to form a team with the maximum performance.

The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.

Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation: 
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) 
and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.

*/
// solution
// The performance of a team is defined as the sum of all members' 
//  speeds multiplied by the minimum efficiency among the members.

// As one can see, the performance of a team depends on two variables.
// To facilitate the enumeration process, let us first fix the value of one of the variables, 
// namely the minimum efficiency of the team. 

//  For each candidate, we treat him/her as the one who has the minimum efficiency in a team. 
//  Then, we select the rest of the team members based on this condition.
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
       vector<pair<int,int>> v;
        for(int i=0;i<speed.size();i++)
            v.push_back({efficiency[i],speed[i]});
        sort(v.rbegin(),v.rend());
        priority_queue<int,vector<int>,greater<int>> pq;
        long long ans=0;
        long long sum=0;
        for(int i=0;i<v.size();i++)//select the ith engineer from the list of candidates as a potential member of the team.
        {
          sum+=v[i].second; //all previous team members upto i must have an efficiency greater than or equal to the first team member.
          /*
             Each of the selected members upto i will have an efficiency that is at least as high as the engineer that was 
             picked  in the first step.
             
             With the minimum effiency fixed, it will be beneficial to pick as many additional members as possible, 
             up to the maximum quota of k-1 members.

         */
	        pq.push(v[i].second);
	        if(pq.size()>k)
	        {
	            sum-=pq.top();
	            pq.pop();
	        }
	        ans = max(ans,v[i].first*sum);
        }
        return ans%(1000000007);
    }
};