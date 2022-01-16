//LINK :https://leetcode.com/problems/unique-paths/

//MEMOISATION
class Solution {
int dp[101][101];
public:
    int uniquePathsAns(int r, int c , int m, int n)
    {
        if(r >=m or c>=n or r<0 or c<0) return 0;
        if(r==m-1 and c==n-1) return 1;
        
        if(dp[r][c]!=-1) return dp[r][c];
        
        int ans1=uniquePathsAns(r,c+1,m,n);
        int ans2=uniquePathsAns(r+1,c,m,n);
        int totpaths=ans1+ans2;
    
        return dp[r][c] = totpaths;
    }
    
    int uniquePaths(int m, int n) {
        
        memset(dp,-1,sizeof(dp));
        return uniquePathsAns(0,0,m,n);
    }
};

//TABULATION
class Solution {
int dp[101][101];
public:  
int uniquePaths(int m, int n) {
        
    for(int i=m-1;i>=0;i--)
    {
       for(int j=n-1;j>=0;j--)
        {
           if(i==m-1)
               dp[i][j]=1;
           else if(j==n-1)
                dp[i][j]=1;
           else
            dp[i][j]=dp[i+1][j]+dp[i][j+1];
        } 
    }
        return dp[0][0];
    }
};
