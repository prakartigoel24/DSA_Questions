// LINK : https://leetcode.com/problems/edit-distance/

//Tabulation - optimised
class Solution {
public:
    int minDistance(string s1, string s2) {
        
        int n = s1.size();
        int m=s2.size();
        
        vector<int> prev (m+1,0), curr(m+1,0);
        
        for(int j=0;j<=m;j++)
        {
            prev[j]=j;
        }
    
        for(int i=1;i<=n;i++)
        {
            curr[0]=i;
            for(int j=1;j<=m;j++)
            {
                int replace=0, del=0, insert =0;
                if(s1[i-1]==s2[j-1])
                {
                   curr[j]= prev[j-1];
                }
                else
                {
                    replace  = 1 + prev[j-1];
                    del = 1 + prev[j];
                    insert = 1 + curr[j-1];
                    curr[j]= min({replace, del, insert});

                }
            }
            prev=curr;   
        }
        return prev[m];  
    }
};


//Tabulation
class Solution {
public:
    int minDistance(string s1, string s2) {
        
        int n = s1.size();
        int m=s2.size();
        
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }
        
        for(int j=1;j<=m;j++)
        {
            dp[0][j]=j;
        }
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int replace=0, del=0, insert =0;
                if(s1[i-1]==s2[j-1])
                {
                   dp[i][j]= dp[i-1][j-1];
                }
                else
                {
                    replace  = 1 + dp[i-1][j-1];
                    del = 1 + dp[i-1][j];
                    insert = 1 + dp[i][j-1];
                    dp[i][j]= min({replace, del, insert});

                }
            }
        }
        
        return dp[n][m];  
        
    }
};


//Memoisation
class Solution {
public:
    int f(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
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
