#LINK : https://leetcode.com/problems/wildcard-matching/

//Space optimised -Tabulation
class Solution {
public: 
    bool isMatch(string s, string p) {

        int n=s.length(), m=p.length();
        vector<bool> curr(m+1,false), next(m+1,false);
        
        next[m]=true; //base case
        
        for(int j=0;j<m;j++) //base case
        {
            bool flag=true;
            for(int k=j;k<m;k++)
            {
                if(p[k]!='*')
                {
                    flag=false;
                    break;
                }
                   
            }
            next[j]=flag;
        }
        
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(s[i]==p[j] or p[j]=='?')
                {
                    curr[j]= next[j+1];
                }
                else if(p[j]=='*')
                {
                   curr[j]= next[j] or curr[j+1];
                }
                else
                {
                    curr[j]= false;
                }
            }
            next=curr;
        }
        
        return next[0];
    }
};


//Tabulation
class Solution {
public: 
    bool isMatch(string s, string p) {

        int n=s.length(), m=p.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        
        dp[n][m]=true; //base case
        
        for(int j=0;j<m;j++) //base case
        {
            bool flag=true;
            for(int k=j;k<m;k++)
            {
                if(p[k]!='*')
                {
                    flag=false;
                    break;
                }
                   
            }
            dp[n][j]=flag;
        }
        
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(s[i]==p[j] or p[j]=='?')
                {
                    dp[i][j]= dp[i+1][j+1];
                }
                else if(p[j]=='*')
                {
                   dp[i][j]= dp[i+1][j] or dp[i][j+1];
                }
                else
                {
                    dp[i][j]= false;
                }

            }
        }
        
        return dp[0][0];
    }
};


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
