#LINK : https://leetcode.com/problems/wildcard-matching/

//Memoisation solution
class Solution {
public:
    bool f(string &s, string &p,int i, int j,vector<vector<int>> &dp)
    {
        int n = s.length(), m = p.length();
        if(i==n and j==m) return true;
        if(j==m) return false;
        if(i==n)
        {
            for(int k=j;k<m;k++)
            {
                if(p[k]!='*')
                    return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==p[j] or p[j]=='?')
        {
            return dp[i][j]= f(s,p,i+1,j+1,dp);
        }
        
        if(p[j]=='*')
        {
            return dp[i][j]= f(s,p,i+1,j,dp) or f(s, p, i,j+1,dp); //star means nothing or star matches one character many times.
        }
        
        
        return dp[i][j]= false;
        
    }
    
    
    bool isMatch(string s, string p) {

        int n=s.length(), m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(s, p, 0, 0,dp);
    }
};
