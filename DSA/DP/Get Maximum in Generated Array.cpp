//LINK :https://leetcode.com/problems/get-maximum-in-generated-array/

//Tabulation [sol-1]
class Solution {
public:
    int getMaximumGenerated(int n) {
        
        int dp[102];
        dp[0]=0; dp[1]=1;
        
        int maxi=1;
        
        if(n<2) return n;
        for(int i=2;i<=n;i++)
        {
            if(i&1)
            {
                dp[i]=dp[i/2]+dp[i/2 +1];
            }
            else
                dp[i]=dp[i/2];
            
            maxi=max(dp[i],maxi);
            
        }
        
        return maxi;
    }
};
