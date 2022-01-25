//LINK : https://leetcode.com/problems/n-th-tribonacci-number/

//SPACE OPTIMISED SOLUTION

//TABULATION
class Solution {
public:
    int tribonacci(int n) {
        
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<=n;i++)
        {
            if(i==0 or i==1) dp[i]=i;
            else if(i==2) dp[i]=1;
            else
            {
                dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
            }
        }
        
        return dp[n];
    }
};
