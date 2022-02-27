//LINK : https://leetcode.com/problems/longest-palindromic-subsequence/

//TABULATION [sol-1] (OPTIMISED SOLUTION)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
         
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        int n =s.length();
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
        
       
        return curr[n]; 
        
    }
};

//TABULATION [Sol-2]
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
         
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        int n =s.length();
        int m =rev.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));


        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==rev[j-1])
                {
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
       
        return dp[n][m]; 
        
    }
};
