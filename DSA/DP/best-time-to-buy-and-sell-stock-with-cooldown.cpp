//LINK : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/


//MEMOISATION
class Solution {
public:
    int dp[5001][2];
    
    int maxProfitWithCooldown(vector<int>& prices,int i, bool own )
    {
        int n=prices.size();
        if(i>=n) return 0;
        
        if(dp[i][own]!=-1) return dp[i][own];
            if(own)
            {
                int op1= prices[i] + maxProfitWithCooldown(prices,i+2,0);
                int op2=  0 + maxProfitWithCooldown(prices,i+1,1);
                return dp[i][own]=max(op1,op2);
            }
            else
            {
                int op1= -prices[i] + maxProfitWithCooldown(prices,i+1,1);
                int op2=  0 + maxProfitWithCooldown(prices,i+1,0);
                return dp[i][own]=max(op1,op2);

            }
        
    }
       
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        if(n==0)
        {
            return 0;
        }
        
        memset(dp,-1,sizeof(dp));
        return maxProfitWithCooldown(prices,0,0);
        
    }
};

//TABULATION
class Solution {
public:
       
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        if(n<=1)
        {
            return 0;
        }
        
        int dp[n][2];
        memset(dp,0,sizeof(dp));
        
        
        dp[0][1]=-prices[0];
        dp[0][0]=0;
        dp[1][1]=max(dp[0][0]-prices[1],dp[0][1]);
        dp[1][0]=max(dp[0][1]+prices[1],dp[0][0]);
        
        
        for(int i=2;i<n;i++)
        {
            dp[i][1]=max(-prices[i] + dp[i-2][0],dp[i-1][1]);
            dp[i][0]=max(dp[i-1][0] , prices[i] + dp[i-1][1]);

        }
        return dp[n-1][0];
        
      
    }
};

