//LINK : https://leetcode.com/problems/maximal-square/

//TABULATION
class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        
        int r=mat.size();
        int c=mat[0].size();
        
        int dp[r+1][c+1];
        memset(dp,0,sizeof(dp));

        int maxi=0;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(mat[i-1][j-1]=='1')
                {
                    dp[i][j]= 1+ min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
                
                maxi=max(maxi,dp[i][j]);

            }
        }
   
        return maxi*maxi;
    }
};
