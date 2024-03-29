// LINK :https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

//TABULATION [sol-1] (OPTIMISED SOLUTION)
class Solution {
public:
    int minInsertions(string s) {
        
        int n=s.length();
        string rev=s;
        reverse(rev.begin(),rev.end());
        
        vector<int> curr(n+1,0), prev(n+1,0);
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==rev[j-1])
                {
                    curr[j]=1+prev[j-1];
                }
                else
                {
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            
            prev=curr;
        }
        
        return n-curr[n];
        
    }
};

//TABULATION [sol-2] 
class Solution {
public:
    int minInsertions(string s) {
        
        int n=s.length();
        string rev=s;
        reverse(rev.begin(),rev.end());
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==rev[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return n-dp[n][n];
        
    }
};
