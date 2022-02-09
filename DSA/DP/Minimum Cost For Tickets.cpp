//LINK : https://leetcode.com/problems/minimum-cost-for-tickets/

//Memoisation
class Solution {
int dp[367];
public:
    int mincost(int i, vector<int>& days, vector<int>& cost )
    {
        int n=days.size();
        
       if(i>365) return 0;
        
        
        if(dp[i]!=NULL) return dp[i];
        long long m1=INT_MAX, m2=INT_MAX, m3=INT_MAX;
        
         if(count(days.begin(), days.end(),i) > 0  )
        {
            m1=cost[0]+mincost(i+1,days, cost);
            m2=cost[1]+mincost(i+7,days, cost);
            m3=cost[2]+mincost(i+30,days, cost);
        
        }
        else
        {
            return mincost(i+1,days, cost);
        }
        
        return dp[i]= min(m1, min(m2, m3));
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        
        memset(dp,NULL,sizeof(dp));
        return mincost(days[0],days,cost);
        
    }
};

//Tabulation
