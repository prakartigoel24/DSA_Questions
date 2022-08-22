// LINK : https://leetcode.com/problems/rotate-image/

// Transpose then swap the columns with their mirror column

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int i=0;i<rows;i++)
        {
            for(int j=i+1;j<cols;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int j=0;j<cols/2;j++)
        for(int i=0;i<rows;i++)
        {
            swap(matrix[i][j],matrix[i][cols-1-j]);
        }
    }
};
