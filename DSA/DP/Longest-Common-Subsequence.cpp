//LINK : https://leetcode.com/problems/longest-common-subsequence/

//TABULATION [SOl-1]
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        
        int n =s1.length();
        int m =s2.length();
        
        int dp[n+1][m+1];
        memset(dp,-1,sizeof(dp));
        
        
        for(int i=n;i>=0;i-- )
        {
            for(int j=m;j>=0;j--)
            {
                if(i== n or j==m) dp[i][j]=0;
                else if(s1[i]==s2[j]) dp[i][j]= 1+dp[i+1][j+1];
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        
        return dp[0][0];
        
    }
};

//MEMOISATION [Sol-2]
class Solution {
public:
    int dp[1001][1001];
    int lcs(int i, int j, string s1, string s2)
    {
        
        if(i>=s1.length() || j>=s2.length())
            return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j])
            return dp[i][j]= 1+ lcs(i+1,j+1,s1,s2);
        else
        {
            int l=lcs(i+1,j,s1,s2);
            int r=lcs(i,j+1,s1,s2);
            
            return dp[i][j]= max(l,r);
        }
        
        
        
    }
    int longestCommonSubsequence(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return lcs(0,0,s1,s2);
    }
};
