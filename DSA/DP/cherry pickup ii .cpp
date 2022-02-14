//LINK : https://leetcode.com/problems/cherry-pickup-ii/

//Optimal Solution
class Solution {
public:    
    int cherryPickup(vector<vector<int>>& grid) {
    
        int r =grid.size();
        int c=grid[0].size();
        
        
        vector<vector<int>> curr(c, vector<int>(c,-1e8));
        vector<vector<int>> front(c, vector<int>(c,-1e8));

        
        int maxi=0, maxAns=0;
       for(int j=0;j<c;j++)
       {
           for(int j1=0;j1<c;j1++)
           {
               if(j==j1){
                   front[j][j1]=grid[r-1][j];
               }
               else
                   front[j][j1]=grid[r-1][j]+grid[r-1][j1];
           }
       }
        
        
       for(int i=r-2;i>=0;i--)
       {
          for(int j1=0;j1<c;j1++)
          {
              for(int j2=0;j2<c;j2++)
              {
                  maxAns=-1e8;
                  for(int p1=-1;p1<=1;p1++)
                  {
                        for(int p2=-1;p2<=1;p2++)
                        {
                            if(j1 == j2)
                            {
                                maxi=grid[i][j1];
                                
                            }
                            else
                            {
                                maxi=grid[i][j1]+grid[i][j2];

                            }
                            
                            
                            if(j1+p1>=0 and j1+p1 <c and j2+p2>=0 and j2+p2<c)
                                 maxi+=front[j1+p1][j2+p2];
                            else
                                maxi+= -1e8;

                            maxAns=max(maxAns, maxi);

                        }

                  }
                  
                  curr[j1][j2]=maxAns;
              }
              
         }
        
           front=curr;
       }
        
       return front[0][c-1];
    }
};


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

//Tabulation
class Solution {
public:    
    int cherryPickup(vector<vector<int>>& grid) {
    
        int r =grid.size();
        int c=grid[0].size();
        
        
        int dp[r+1][c+1][c+1];
        memset(dp,-1e8,sizeof(dp));
        
        int maxi=0, maxAns=0;
       for(int j=0;j<c;j++)
       {
           for(int j1=0;j1<c;j1++)
           {
               if(j==j1){
                   dp[r-1][j][j1]=grid[r-1][j];
               }
               else
                   dp[r-1][j][j1]=grid[r-1][j]+grid[r-1][j1];
           }
       }
        
        
       for(int i=r-2;i>=0;i--)
       {
          for(int j1=0;j1<c;j1++)
          {
              for(int j2=0;j2<c;j2++)
              {
                  maxAns=-1e8;
                  for(int p1=-1;p1<=1;p1++)
                  {
                        for(int p2=-1;p2<=1;p2++)
                        {
                            if(j1 == j2)
                            {
                                maxi=grid[i][j1];
                                
                            }
                            else
                            {
                                maxi=grid[i][j1]+grid[i][j2];

                            }
                            
                            
                            if(j1+p1>=0 and j1+p1 <c and j2+p2>=0 and j2+p2<c)
                                 maxi+=dp[i+1][j1+p1][j2+p2];
                            else
                                maxi+= -1e8;

                            maxAns=max(maxAns, maxi);

                        }

                  }
                    
                  
                  dp[i][j1][j2]=maxAns;
                
            } 
         }
           
       }

        
       return dp[0][0][c-1];
    }
};
