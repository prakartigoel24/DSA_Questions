//LINK : https://leetcode.com/problems/knight-dialer/

#define mod 1000000007
class Solution {
int dp[5001][4][4];
public:
    int kd(int n , int jumps ,int i, int j, vector<vector<bool>> &vis)
    {
        if(i>=4 or j>=3 or i<0 or j<0 or jumps < 0 or vis[i][j]==true)
        {
            return 0;
        }
        
        if(jumps==0)
        {
            return 1;
        }
        
        if(dp[jumps][i][j]!=-1) return dp[jumps][i][j];
        long long a1= kd(n, jumps-1 , i-2,  j+1, vis);
        long long a2= kd(n, jumps-1 , i-2,  j-1, vis);
        long long a3= kd(n, jumps-1 , i-1,  j+2, vis);
        long long a4= kd(n, jumps-1 , i-1,  j-2, vis);
        long long a5= kd(n, jumps-1 , i+1,  j+2, vis);
        long long a6= kd(n, jumps-1 , i+1,  j-2, vis);
        long long a7= kd(n, jumps-1 , i+2,  j+1, vis);
        long long a8= kd(n, jumps-1 , i+2,  j-1, vis);

            
        return dp[jumps][i][j] =(long long)(a1+a2+a3+a4+a5+a6+a7+a8)%mod;
    }
    
    
    int knightDialer(int n) {
        
        memset(dp,-1,sizeof(dp));
        vector<vector<bool>> vis(4,vector<bool>(3,0));
        vis[3][0]=1;
        vis[3][2]=1;
        
        long long ans=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                if((i==3 and j==0) or (i==3 and j==2)) 
                    continue;
                
                ans += kd(n,n-1,i,j,vis)%mod;
            }
        }
        
        return ans%mod;
        
    }
};
