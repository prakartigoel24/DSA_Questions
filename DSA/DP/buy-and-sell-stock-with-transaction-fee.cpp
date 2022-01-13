//LINK : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

//using MEMOIZATION

class Solution {
    int dp[50001][2];
public:
    
int maxProfitWithFee(int i,bool own,int fee, vector<int> &prices)
{
  if(i==prices.size())
    return 0;

  if(dp[i][own]!=-1) return dp[i][own];
    
  if(own)
  {
      int op1= prices[i] + maxProfitWithFee(i+1,0,fee,prices);
      int op2= maxProfitWithFee(i+1,own,fee,prices);
      return dp[i][own]=max(op1,op2);
  }
  else
  {
      int op1= -(prices[i]+fee) + maxProfitWithFee(i+1,1,fee,prices);;
      int op2=  maxProfitWithFee(i+1,0,fee,prices);;
      return dp[i][own]=max(op1,op2);
  }

}
    
int maxProfit(vector<int>& arr, int fee) {
          memset(dp,-1,sizeof(dp));
          
          return maxProfitWithFee(0,0,fee,arr);
    }
};


//USING TABULATION

class Solution {
    int dp[50001][2];
    public:
    int maxProfit(vector<int>& prices, int fee) {
              memset(dp,-1,sizeof(dp));

            int n = prices.size();
            if(n<=1) return 0;

            dp[0][0]=0;
            dp[0][1]= -(prices[0]+fee);

            for(int i=1;i<n;i++)
            {
                dp[i][1]=max(-(prices[i]+fee) + dp[i-1][0]  ,dp[i-1][1] );
                dp[i][0]=max( prices[i] + dp[i-1][1] , dp[i-1][0]);

            }

             return dp[n-1][0];
        }
    };
