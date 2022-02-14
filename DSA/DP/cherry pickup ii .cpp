//LINK : https://leetcode.com/problems/cherry-pickup-ii/

//Memoisation

class Solution {
int dp[75][75][75];
public:
    int cherrycollect(vector<vector<int>>& grid, int i, int j1,int j2, int r, int c)
    {
        
        if(j1<0 or j2<0 or j1>=c or j2>=c)
        {
            return -1e8;
        }
        
        if(i==r-1)
        {
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        
        if( dp[i][j1][j2]!=NULL) return  dp[i][j1][j2];
        
        
        int maxi=0;
        
        for(int p1=-1;p1<=1;p1++)
        {
            for(int p2=-1;p2<=1;p2++)
            {
                if(j1 == j2)
                {
                    maxi= max(maxi,grid[i][j1] +cherrycollect(grid,i+1,j1+p1,j2+p2,r, c) );
                }
                else
                {
                   maxi=max(maxi, grid[i][j1] + grid[i][j2]+cherrycollect(grid,i+1,j1+p1,j2+p2,r, c) );

                }
                
            } 
        }
        
        return dp[i][j1][j2]= maxi;
        
    }
    
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        memset(dp,NULL,sizeof(dp));
        int r =grid.size();
        int c=grid[0].size();
        
       return cherrycollect(grid,0,0,c-1,r, c );

    }
};
