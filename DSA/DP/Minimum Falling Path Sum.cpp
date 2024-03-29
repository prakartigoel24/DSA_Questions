//LINK : https://leetcode.com/problems/minimum-falling-path-sum/

//WITHOUT DP Table - o(1) space [ sol-1]

public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        
        int n=mat.size() ;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                
                if(i==n-1)
                {
                    continue;
                }
                else if(j==n-1)
                {
                    mat[i][j]= mat[i][j] + min(mat[i+1][j],mat[i+1][j-1]);
                }
                else if(j==0)
                {
                    mat[i][j]= mat[i][j] + min(mat[i+1][j],mat[i+1][j+1]);

                }
                else
                {
                    mat[i][j]= mat[i][j] + min( mat[i+1][j], min(mat[i+1][j-1],mat[i+1][j+1]) );

                }
            }
        }
        
        int m=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            m=min(m,mat[0][i]);
        }
        
        return m;
    }
};

//TABULATION - o(n*n) space [sol-2]
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        
        int n=mat.size() ;
        vector<vector<int>> dp(n,vector<int> (n,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                
                if(i==n-1)
                {
                    dp[i][j]=mat[i][j];
                }
                else if(j==n-1)
                {
                    dp[i][j]= mat[i][j] + min(dp[i+1][j],dp[i+1][j-1]);
                }
                else if(j==0)
                {
                    dp[i][j]= mat[i][j] + min(dp[i+1][j],dp[i+1][j+1]);

                }
                else
                {
                    dp[i][j]= mat[i][j] + min( dp[i+1][j], min(dp[i+1][j-1],dp[i+1][j+1]) );

                }
            }
        }
        
        int m=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            m=min(m,dp[0][i]);
        }
        
        return m;
    }
};
