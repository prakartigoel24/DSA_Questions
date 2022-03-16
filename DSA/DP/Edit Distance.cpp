// LINK : https://leetcode.com/problems/edit-distance/

//Memoisation
class Solution {
public:
    int f(string s1, string s2, int i, int j, vector<vector<int>> &dp)
    {
        if(i==0)
        {
            return j;
        }
        if(j==0)
        {
            return i;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int replace=0, del=0, insert =0;
        if(s1[i-1]==s2[j-1])
        {
            return dp[i][j]= f(s1, s2, i-1,j-1,dp);
        }
        else
        {
            replace  = 1 + f(s1, s2, i-1 , j-1, dp);
            del = 1 + f(s1, s2 ,i-1, j, dp);
            insert = 1 + f(s1, s2, i,j-1, dp);
            
            return dp[i][j]= min({replace, del, insert});
            
        }
    
        
    }
    int minDistance(string s1, string s2) {
  
        int n = s1.size();
        int m=s2.size();
        
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        
        return f(s1, s2,n,m,dp);
        
        
        
    }
};
