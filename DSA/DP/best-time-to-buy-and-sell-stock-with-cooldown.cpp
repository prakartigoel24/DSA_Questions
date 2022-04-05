//LINK : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

//TABULATION
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        dp[n][0]=dp[n][1]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                long long profit=0;
                if(j)
                {
                    dp[i][j] = max(-prices[i]+dp[i+1][0] , dp[i+1][1]);
                }
                else
                {
                    dp[i][j] = max(prices[i]+ (i+2<n ?dp[i+2][1] : 0),dp[i+1][0]);
                }
            }
        }
        
       return dp[0][1];
    }
    
};

//MEMOISATION 
class Solution {
public:
     int maxPro(vector<int>& prices, int i, int canbuy , vector<vector<int>> &dp)
    {
        int n=prices.size();
        
        if(i==n)
            return 0;
        
        if(dp[i][canbuy]!=-1) return dp[i][canbuy];
        long long profit=0;
        if(canbuy)
        {
            profit = max(-prices[i]+maxPro(prices,i+1,0, dp) ,maxPro(prices,i+1,1,dp));
        }
        else
        {
            profit = max(prices[i]+ (i+2 < n ? maxPro(prices,i+2,1,dp):0), maxPro(prices, i+1,0,dp));
        }
        
        return dp[i][canbuy] = profit;        
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        
        return maxPro(prices,0,1,dp);
    }
};
