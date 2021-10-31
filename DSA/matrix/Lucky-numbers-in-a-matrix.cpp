//LINK : https://leetcode.com/problems/lucky-numbers-in-a-matrix/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        
        vector<int> armin(mat.size()) ;
        vector<int> ans; 
       
          for(int i=0;i<mat.size();i++)
          {
                armin[i]=*min_element(mat[i].begin(),mat[i].end());
          }             

        
        for(int i=0;i<mat[0].size();i++)
       {
           int maxele=INT_MIN;
           
        for(int j=0;j<mat.size();j++)
        {
            maxele=max(maxele,mat[j][i]);
        }
           
           if(find(armin.begin(),armin.end(),maxele)!=armin.end())
           {
               ans.push_back(maxele);
           }

      }
                          
       return ans;
    }
};
