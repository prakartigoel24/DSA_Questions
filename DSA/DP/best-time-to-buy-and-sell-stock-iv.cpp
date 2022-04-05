//LINK : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

//OPTIMISED SOLUTION
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

       int n=prices.size();        
        vector<vector<int>> next (2,vector<int>(k+1,0)) ,cur(2,vector<int>(k+1,0));       
        
        for(int i=n-1;i>=0;i--)
        {
            for(int canbuy=0;canbuy<=1;canbuy++)
            {
                for(int cap=1;cap<=k;cap++)
                {
                    if(canbuy)
                    {
                        cur[canbuy][cap] = max(-prices[i]+next[0][cap] ,next[1][cap]);
                    }
                    else
                    {
                       cur[canbuy][cap] = max(prices[i]+next[1][cap-1], next[0][cap]);
                    }
        
                }
            }
            
            next=cur;
        }
        
        return cur[1][k];
        
    }
};

//TABULATION
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n=prices.size();        
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>>(2,vector<int>(k+1,0)));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int canbuy=0;canbuy<=1;canbuy++)
            {
                for(int cap=1;cap<=k;cap++)
                {
                    if(canbuy)
                    {
                        dp[i][canbuy][cap] = max(-prices[i]+dp[i+1][0][cap] ,dp[i+1][1][cap]);
                    }
                    else
                    {
                       dp[i][canbuy][cap] = max(prices[i]+dp[i+1][1][cap-1], dp[i+1][0][cap]);
                    }
        
                }
            }
        }
        
        return dp[0][1][k];
    }
};


//MEMOISATION
class Solution {
public:
    int maxPro(vector<int>& prices, int i, int canbuy ,int cap, vector<vector<vector<int>>> &dp )
    {
        int n=prices.size();
        
        if(cap==0) return 0;
        if(i==n) return 0;

        if(dp[i][canbuy][cap]!=-1) return dp[i][canbuy][cap];
        long long profit=0;
        if(canbuy)
        {
            profit = max(-prices[i]+maxPro(prices,i+1,0,cap, dp) ,maxPro(prices,i+1,1,cap,dp));
        }
        else
        {
            profit = max(prices[i]+maxPro(prices,i+1,1,cap-1,dp), maxPro(prices, i+1,0,cap,dp));
        }
        
        return dp[i][canbuy][cap] = profit;        
    }

    int maxProfit(int k, vector<int>& arr) {

          int n=arr.size();

        vector<vector<vector<int>>> dp (n, vector<vector<int>>(2,vector<int>(k+1,-1)));
       return maxPro(arr,0,1,k,dp);
    }
};
