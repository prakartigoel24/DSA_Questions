// LINK : https://leetcode.com/problems/shortest-common-supersequence/

//Tabulation [sol-1]
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n=str1.length();
        int m=str2.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

       //finding Length of LCS

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        //Using LCS table to find Shortest Common Supersequence 
        // -->  Taking common char once i.e. taking LCS once in the supersequence
        int ii=n, jj=m;
        
        string ans="";
        
        while(ii>0 and jj>0)
        {
            if(str1[ii-1]==str2[jj-1])
            {
                ans=str1[ii-1]+ans;
                ii--,jj--;
            }
            else if(dp[ii-1][jj] > dp[ii][jj-1])
            {
                 ans=str1[ii-1]+ans;
                 ii--;
            }
            else
            {
                ans=str2[jj-1]+ans;        
                jj--;
                
            }
        }
        
        
        while(ii>0)
        {
            ans=str1[ii-1]+ans;
            ii--;
        }
        
         
        while(jj>0)
        {
            ans=str2[jj-1]+ans;
            jj--;
        }
    
        return ans;
      
    }
};
