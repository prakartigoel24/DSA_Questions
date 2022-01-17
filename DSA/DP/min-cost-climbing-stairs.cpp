//LINK :https://leetcode.com/problems/min-cost-climbing-stairs/

//OPTIMAL SPACE SOLUTION [ O(1)-space ]
class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) {
        
       int n=cost.size();
       if(n==0) return 0;
       int prev=0;
       int prev2=0;
       int ans;
    
       for(int i=n-1;i>=0;i--)
       {
           int ans1= cost[i]+prev;
           int ans2= cost[i]+prev2;
           
           ans=min(ans1,ans2);
           
           prev2=prev;
           prev=ans;
       }
     return min(prev2,prev);
    }
};


//MEMOISATION
class Solution {
int dp[1001];
public:
    int minCost(vector<int>& cost,int i)
    {
        int n=cost.size();
        if(i==n)return 0;
        
        if(dp[i]!=-1) return dp[i];
        int jump1 = cost[i] + minCost(cost,i+1);
        int jump2= cost[i] + (i < n-1?minCost(cost,i+2):0);
        return dp[i]=min(jump1,jump2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
       int n=cost.size();
       memset(dp,-1,sizeof(dp));

       int ans1=minCost(cost,0);
       int ans2=minCost(cost,1);
        
       return min(ans1,ans2);
        
    }
};

//TABULATION
class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) {
        
       int n=cost.size();
       int dp1[n+1];
       dp1[n]=0;
    
       for(int i=n-1;i>=0;i--)
       {
           int ans1= cost[i]+dp1[i+1];
           int ans2= cost[i]+ (i<n-1?dp1[i+2]:0);
           
           dp1[i]=min(ans1,ans2);
       }
        
       return min(dp1[0],dp1[1]);
    }
};
