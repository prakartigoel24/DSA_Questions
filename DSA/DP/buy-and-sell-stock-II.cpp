//LINK : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

//Most optimised approach 
//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
      vector<int> next(2,0), cur(2,0);
        
        next[0]=next[1]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                long long profit=0;
                if(j)
                {
                    cur[j] = max(-prices[i]+next[0] , next[1]);
                }
                else
                {
                    cur[j] = max(prices[i]+next[1],next[0]);
                }
            }
            next=cur;
        }
        
       return next[1];
    }
};

//Approach-1 (Tabulation)

//Tabulation
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
                    dp[i][j] = max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
            }
        }
        
       return dp[0][1];
    }
};




//Approach-2 (memoisation)

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
            profit = max(prices[i]+maxPro(prices,i+1,1,dp), maxPro(prices, i+1,0,dp));
        }
        
        return dp[i][canbuy] = profit;        
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        return maxPro(prices,0,1, dp);
    }
};


//Approach -3
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        
        int buy=0, sell=0, totProfit=0;
        
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i] >  arr[i-1])
                sell++;
            else
            {
                totProfit+=(arr[sell]-arr[buy]);
                buy=sell=i;
            }
        }
        
        totProfit+=(arr[sell]-arr[buy]);
        
        return totProfit;
        
    }
};

