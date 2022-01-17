//LINK : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

//TABULATION
class Solution {
public:
    
    int maxProfitWithATM2trans(vector<int>& arr,int k)
    {
          int n=arr.size();
          if(n<=1 or k==0) return 0;

         int dp[k+1][n];
         memset(dp,0,sizeof(dp));
         int maxi;
         for(int i=1;i<=k;i++)
         {
             maxi=INT_MIN;
           for(int j=1;j<n;j++)
           {
               maxi=max(maxi,dp[i-1][j-1]-arr[j-1]);
               dp[i][j]=max(maxi+arr[j],dp[i][j-1]);
           }
        }
        
        return dp[k][n-1];
    }
   
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        if(n==0) return 0;
        
        return maxProfitWithATM2trans(prices,2);
        
    }
};
