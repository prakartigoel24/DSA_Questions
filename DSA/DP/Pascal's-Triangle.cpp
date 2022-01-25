//LINK : https://leetcode.com/problems/pascals-triangle/

//MEMOISATION
class Solution {
public:
    vector<vector<int>> generate2(int numRows,vector<vector<int>> &ans)
    {
         vector<vector<int>> dp(numRows,vector<int>(numRows,1));
        
        if(numRows==1)
        {    
            return ans= dp;
        }
        if(!ans.empty()) return ans;
        
        dp=generate2(numRows-1,ans);
        vector<int> newTemp(numRows,0);
        
        for(int i=0;i<numRows;i++)
        {
            if(i==0 or i==numRows-1)
            {
                newTemp[i]=1;
            }
            else
            {
                newTemp[i]= dp[numRows-2][i]+dp[numRows-2][i-1];
            }
        }
            
        dp.push_back(newTemp);
        
        return ans=dp;
            
    }

vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        
      return generate2(numRows,ans);
    }
};

//RECURSION

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
         vector<vector<int>> dp(numRows,vector<int>(numRows,1));
        
        if(numRows==1)
        {    
            return dp;
        }
        
        
        dp=generate(numRows-1);
        vector<int> newTemp(numRows,0);
        for(int i=0;i<numRows;i++)
        {
            if(i==0 or i==numRows-1)
            {
                newTemp[i]=1;
            }
            else
            {
                newTemp[i]= dp[numRows-2][i]+dp[numRows-2][i-1];
            }
        }
            
        dp.push_back(newTemp);
        
        return dp;
            
    }
};
