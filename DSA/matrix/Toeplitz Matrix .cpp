//LINK : https://leetcode.com/problems/toeplitz-matrix/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        
        int r=mat.size();
        int c=mat[0].size();
        for(int i = 0 ;i <r ;i++)
        {
            for(int j=0 ;j < c ; j++)
            {
                if(i>0 && j >0  and (mat[i-1][j-1]!=mat[i][j]) ) //if current element is not equal to the previous element then return false
                {
                   return false;
                }
                
            }
       
        }
        return true ;
        
    }
};
