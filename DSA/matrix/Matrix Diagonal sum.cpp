//LINK : https://leetcode.com/problems/matrix-diagonal-sum/

//brute force
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int sum=0; int n=mat.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j or i+j==mat[0].size()-1)
                    sum+=mat[i][j];
            }
        }
        
        return sum;
    }
};


//optimised
int diagonalSum(vector<vector<int>>& mat) {
        
        int sum=0; int n=mat.size();
        
        //optimised
        
        for(int i=0;i<n;i++)
        {
            sum+=mat[i][i];
            sum+=mat[i][n-1-i];
        }
        
        if (n%2==0 )
            return sum;
        else
        return sum-mat[n/2][n/2];
}
        
