//LINK : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

//MOST OPTIMISED SOLUTION
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        if(n==0) return 0;
        
        vector<vector<int>> next (2,vector<int>(3,0)) ,cur(2,vector<int>(3,0));       
        
        for(int i=n-1;i>=0;i--)
        {
            for(int canbuy=0;canbuy<=1;canbuy++)
            {
                for(int cap=1;cap<=2;cap++)
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
        
        return cur[1][2];
        
    }
};





//Tabulation [sol-2]
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        if(n==0) return 0;
        
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>>(2,vector<int>(3,0)));
        
//--> no need to assign valueS as zero because array is initialized with zero values already.
//         for(int i=0;i<n;i++)
//         {
//             for(int buy=0;buy<=1;buy++)
//             {
//                 dp[i][buy][0]=0;    //if (cap==0) return 0; (base case)
//             }
//         }
        
//         for(int buy=0;buy<=1;buy++)
//         {
//             for(int cap=0;cap<=2;cap++)
//             {
//                 dp[n][buy][cap]=0;    //if (n==0) return 0;  (base case)
//             }
//         }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int canbuy=0;canbuy<=1;canbuy++)
            {
                for(int cap=1;cap<=2;cap++)
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
        
        return dp[0][1][2];
        
    }
};

//Memoisation [sol-3]
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

    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        if(n==0) return 0;
        
        vector<vector<vector<int>>> dp (n, vector<vector<int>>(2,vector<int>(3,-1)));
        return maxPro(prices,0,1,2,dp);
        
    }
};
