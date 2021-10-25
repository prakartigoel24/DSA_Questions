//LINK : https://leetcode.com/problems/transpose-matrix/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& m) {
        
        int a=m.size();
        int b=m[0].size();
        vector<vector<int>> ans(b,vector<int>(a));
        
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                ans[j][i]=m[i][j];
            }
        }
        
        
        return ans;
        
    }
};
