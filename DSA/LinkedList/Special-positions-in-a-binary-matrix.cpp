//LINK : https://leetcode.com/problems/special-positions-in-a-binary-matrix/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
     vector<vector<int>> zeros (mat.size(),vector<int> (mat[0].size(),0));
     vector<vector<int>> ones (mat.size(),vector<int> (mat[0].size(),1));
        
        
        if(mat==zeros or mat==ones) return 0;
        int ans=0;
        
        vector<int> onesrow(mat.size());
         vector<int> onesCol(mat[0].size());
        
        for(int i=0;i<mat.size();i++)
        {
            for(auto j :mat[i] )
            {
                if(j==1)
                    onesrow[i]++;
            }
            
        }
  
        for(int i=0;i<mat[0].size();i++)
        {
        
            for(int j=0;j<mat.size();j++)
            {
                if(mat[j][i]==1)
                {
                    onesCol[i]++;
                }
            }
    
        }
        
        
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1 and onesrow[i]<=1 and onesCol[j]<=1)
                    ans++;
            }
        }
        
        return ans;
    }
};
