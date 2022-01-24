//LINK : https://leetcode.com/problems/perfect-squares/

//TABULATION
class Solution {
public:
    int numSquares(int n) {
        
        if(n<=3) return n;
        
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;

        for(int i=4;i<=n;i++)
        {
            for(int j=1;j*j <=i ;j++)
            {
                dp[i]=min(dp[i],dp[i - (j*j)]);
            }
            dp[i]+=1;  
        }
        
        return dp[n];
    }
};
