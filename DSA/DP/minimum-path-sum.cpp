//LINK :https://leetcode.com/problems/minimum-path-sum/

//LINK :https://leetcode.com/problems/minimum-path-sum/

//TABULATION  * SC- O(1) *
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m =grid.size();
        int n=grid[0].size();

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 and j==n-1) continue;
                
                if(i==m-1)
                    grid[i][j]+=grid[i][j+1];
                    
                else if(j==n-1)
                    grid[i][j]+=grid[i+1][j];
                    
                else
                {
                    grid[i][j]+=min(grid[i+1][j],grid[i][j+1]);
                }
            }
        }
        
        return grid[0][0]; 
    }
};


//TABULATION   * SC- O(M*N) *
class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        
        int m =grid.size();
        int n=grid[0].size();
        
        int dp[m+1][n+1];
        memset(dp,-1,sizeof(dp));
        dp[m-1][n-1]=grid[m-1][n-1];
        
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 and j==n-1) continue;
                dp[i][j]=grid[i][j];
                
                if(i==m-1)
                    dp[i][j]=grid[i][j]+dp[i][j+1];
                    
                else if(j==n-1)
                    dp[i][j]=grid[i][j]+dp[i+1][j];
                    
                else
                {
                    dp[i][j]+=min(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        
        return dp[0][0];
        
    }
};
