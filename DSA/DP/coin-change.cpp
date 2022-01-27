//LINK : https://leetcode.com/problems/coin-change/

//MEMOISATION
class Solution {
int dp[10010];
public:
    int mincoins(vector<int>& coins, int amo)
    {
        int n=coins.size();
        
        if(amo==0) return  0;
        
        if(dp[amo]!=-1) return dp[amo];
        
        int m=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(amo-coins[i]>=0)
            m = min(m + 0LL,mincoins(coins,amo-coins[i])+1LL);   
        }
         return dp[amo]= m;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        memset(dp,-1,sizeof(dp));
        
        int ans= mincoins(coins,amount);
        return ans==INT_MAX ? -1: ans;
    }
};

//TABULATION
