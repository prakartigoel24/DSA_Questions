//LINK: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        
        int n =mat.size();
        int p=0;
        
        if(mat==target) return true;
        
    while(p<3)
    {
    //finding TRANSPOSE
        for(int i =0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }
        
    // REVERSING matrix
        
        reverse(mat.begin(),mat.end());
        
        //reverse using looping 
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n/2 ; j++)
        //     {
        //         swap(mat[i][j] , mat[i][n-j-1]);
        //     }
        // }
        
        if(mat==target) return true ;
            
        p++;
        }
        
        return false;
    }
};
