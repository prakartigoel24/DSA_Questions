//LINK : https://leetcode.com/problems/triangle/

//SPACE OPTIMISED SOLUTION - O(1)
class Solution {
public:
   int minimumTotal(vector<vector<int>>& triangle) {
        
        int r=triangle.size();
        
        if(r==1) return triangle[0][0];
 
        for(int i=r-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                 triangle[i][j]=triangle[i][j]+min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        
        return triangle[0][0];
    }
};

//TABULATION - O(r*r)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int r=triangle.size();
        
        if(r==1) return triangle[0][0];
        
        int dp[r][r];
        memset(dp,INT_MAX,sizeof(dp));
        
        
        for(int i=r-1;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                if(i==r-1)
                {
                    dp[i][j]=triangle[i][j];
                }
                else
                {
                    dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
                }
            }
        }
        
        return dp[0][0];
        
    }
};
