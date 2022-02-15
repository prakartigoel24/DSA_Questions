//LINK : https://leetcode.com/problems/minimum-cost-for-tickets/

//Tabulation [SOL-1]
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        
        int n=days.size();
        
        int dp[n+1];
        memset(dp,INT_MAX,sizeof(dp));
        
        dp[n]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            int d7 =i, d30=i;
            while(d7<n and days[d7] < days[i]+7) d7++;
            while(d30<n and days[d30] < days[i]+30) d30++;
            
            dp[i]=min(dp[i+1]+cost[0], min(dp[d7]+cost[1], dp[d30]+cost[2]));
        }
        
        return dp[0];
    }
};

//Memoisation [SOL-2]
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


