//LINK : https://leetcode.com/problems/out-of-boundary-paths/

//MEMOISATION
#define mod 1000000007

int dp[100][100][100];
class Solution {
public:
    long long paths(int m, int n , int i, int j, int mm, int maxMove)
    {
        
        if(i>=m or j>=n or i<0 or j<0)
        {
            return 1;
        }
        else if(mm==maxMove)
        {
            
                return 0;
        }
        
        if(dp[i][j][mm]!=-1) return dp[i][j][mm];
         long long m1=paths(m , n , i+1,j,mm+1,maxMove)%mod;
         long long m2=paths(m , n , i,j+1,mm+1,maxMove)%mod;
         long long m3=paths(m , n , i-1,j,mm+1,maxMove)%mod;
         long long m4=paths(m , n , i,j-1,mm+1,maxMove)%mod;
        
        return dp[i][j][mm]=(m1+m2+m3+m4+0LL)%mod;
        
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp,-1,sizeof(dp));
        return paths(m , n ,startRow,startColumn,0, maxMove)%mod;
    }
};
