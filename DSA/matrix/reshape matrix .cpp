//LINK : https://leetcode.com/problems/reshape-the-matrix/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        vector<vector<int>> ans(r, vector<int> (c,0)) ;
        
       int n = mat[0].size();
       int m= mat.size();
       int  matsize=n*m;
       int newsize=r*c;
        
       int x=0, y=0;
    
        if(matsize!=newsize)
        {
            return mat;
        }
        
        else
        {
            
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                   ans[i][j]=mat[x][y];
                   
                    if(y==n-1)
                    {
                        y=0;
                        x++;
                    }
                    else
                        y++;
                    
                }
        
            }   
            
            return ans;
        }
        
    
        
    }
};
