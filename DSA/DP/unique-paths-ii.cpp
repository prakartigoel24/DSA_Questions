//LINK : https://leetcode.com/problems/unique-paths-ii/

// MOST OPTIMISED -without DP array
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();

        if(grid[m-1][n-1]==1 or grid[0][0]==1) return 0;

        for(int i=0;i<= m-1;i++)
        {
            for(int j=0;j<= n-1;j++)
            {
                if(i==0 and j==0) grid[i][j]=1;
                else if(grid[i][j]==1) grid[i][j]=0;
                else 
                {
                    int up=0, left=0;
                    if(i > 0)  up=grid[i-1][j];
                    if(j > 0) left=grid[i][j-1];

                    grid[i][j]=up+left;

                }

            }
        }
        return grid[m-1][n-1];
    }
};

//TABULATION
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));

        if(grid[m-1][n-1]==1 or grid[0][0]==1) return 0;

        for(int i=0;i<= m-1;i++)
        {
            for(int j=0;j<= n-1;j++)
            {
                if(i==0 and j==0) dp[i][j]=1;
                else if(grid[i][j]==1) dp[i][j]=0;
                else 
                {
                    int up=0, left=0;
                    if(i > 0)  up=dp[i-1][j];
                    if(j > 0) left=dp[i][j-1];

                    dp[i][j]=up+left;

                }

            }
        }
        return dp[m-1][n-1];
    }
};

//MEMOISATION
class Solution {
public:
    int paths(int i , int j ,vector<vector<int>>& grid ,vector<vector<int>>& dp)
    {
       int m = grid.size();
       int n = grid[0].size();

    if(i>=m or j>=n or grid[i][j]==1 or (m==1 and n==1 and grid[m-1][n-1]==1 )) return 0;

         if(i==m-1 and j == n-1 and !grid[i][j]) return 1;


        if(dp[i][j]!=-1) return dp[i][j];
        int down = paths(i+1,j,grid,dp) ;
        int right = paths(i,j+1,grid,dp);

        return dp[i][j] = down+right;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
       int m = grid.size();
       int n=grid[0].size();


        vector<vector<int>> dp(m,vector<int>(n,-1));
    return paths(0,0,grid,dp);
    }
};
