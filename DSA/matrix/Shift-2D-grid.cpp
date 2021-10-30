//LINK : https://leetcode.com/problems/shift-2d-grid/

//brute force

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid1, int k) {
        
       
        int m=grid1.size();
        int n=grid1[0].size();
     
       vector<vector<int>> grid=grid1;
        if(k==0 or k==m*n)
            return grid;
        
    while(k> m*n) k=k-(m*n);
        
       while(k--)
       {
          
           for(int i=0;i<m;i++)
           {
               for(int j =0;j< n-1 ;j++)
               {
                   grid[i][j+1]=grid1[i][j];
               }
           }
         
           
           for(int i=0;i<m-1;i++)
           {
              
                   grid[i+1][0]=grid1[i][n-1];
               
           }
           
            grid[0][0]=grid1[m-1][n-1];
           
           
           
          grid1=grid;
 
       }
        return grid1;
    }
};
