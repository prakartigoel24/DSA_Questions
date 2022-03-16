//LINK : https://leetcode.com/problems/distinct-subsequences/

//Tabulation - optimised
class Solution {
public:

    int numDistinct(string s, string t) {
        int n =s.size();
        int m=t.size();
        vector<double> curr(m+1,0) , prev(m+1,0) ; 
       
        curr[0]=1;
        prev[0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                double take=0 , nottake=0;
                if(s[i-1]==t[j-1])
                {
                    take=prev[j-1];
                    nottake = prev[j];
                     curr[j]= take+nottake;
                }
               else
               {
                     curr[j]= prev[j];
               }
            }
            
            prev=curr;
        }
        
        
        return (int)prev[m];
    }
};


//Tabulation -2
class Solution {
public:

    int numDistinct(string s, string t) {
        int n =s.size();
        int m=t.size();
        vector<vector<double>> dp(n+1,vector<double> (m+1,-1));
       
        for(int j=1;j<=m;j++)
        {
            dp[0][j] = 0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                double take=0 , nottake=0;
                if(s[i-1]==t[j-1])
                {
                    take=dp[i-1][j-1];
                    nottake = dp[i-1][j];
                     dp[i][j]= take+nottake;
                }
               else
               {
                     dp[i][j]= dp[i-1][j];
               }
            }
        }
        
        
        return (int)dp[n][m];
    }
};


//Memoisation 
class Solution {
public:
    int f(string &s, string &t , int i, int j, vector<vector<int>> &dp)
    {
        if(j==0) return 1;

        if(i==0 ) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int take=0 , nottake=0;
        if(s[i-1]==t[j-1])
        {
            take=f(s, t, i-1, j-1, dp);
            nottake = f(s, t, i-1,j, dp);
            return dp[i][j]= take+nottake;
        }
       else
        return dp[i][j]= f(s, t, i-1, j, dp);
    }
    int numDistinct(string s, string t) {
        int n =s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
       
        return f(s, t , n, m, dp);
    }
};
