// LINK : https://leetcode.com/problems/search-a-2d-matrix/

//Approach -1 [TC - O(log(m*n) ]
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int row = mat.size();
        int col = mat[0].size();
           
        int lo=0; int hi = row*col - 1;
        
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            int r = mid/col;
            int c = mid%col;
            
            if(mat[r][c]==target)
            {
                return true;
            }
            else if(mat[r][c] < target)
            {
                lo=mid+1;
            }
            else
                hi = mid-1;
        }
        
        return false;
    }
};

//Approach -2 [TC - O(N+M)]
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int row = mat.size();
        int col = mat[0].size();
        int i = 0 , j = col-1;
        
        while(j>=0 and i<row)
        {
            if(mat[i][j]==target) return true;
            else if(mat[i][j] < target)
            {
                i++;
            }
            else
                j--;
        }
        return false;
    }
};

//Approach -3  [TC - O(N*logM)]
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
