// LINK : https://leetcode.com/problems/search-a-2d-matrix/

//Approach -1  [TC - O(N*logM)]
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int row = mat.size();
        int col = mat[0].size();
       
        for(int i=0;i<row;i++)
        {
            int l=0, r= col-1;
            while(l<=r)
            {
                int mid = (l+r)/2;
                
                if(mat[i][mid]==target) 
                    return true;
                else if(mat[i][mid] > target)
                {
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
        }
        return false;
    }
};
