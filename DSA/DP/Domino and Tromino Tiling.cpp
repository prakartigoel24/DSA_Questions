//link : https://leetcode.com/problems/domino-and-tromino-tiling/

//TABULATION
class Solution {
public:
    int numTilings(int n) {
        
        if(n==1 or  n==2)return n;
        vector<long long > dp(n+1);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        
        for(int i=4;i<=n;i++)
        {
            dp[i]= (2*dp[i-1]+dp[i-3])%1000000007;
        }
        
     return dp[n]%1000000007;
    }
};
