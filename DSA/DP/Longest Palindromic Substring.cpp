// LINK : https://leetcode.com/problems/longest-palindromic-substring/

//TABULATION [sol-1] (DP)
class Solution {
public:
    string longestPalindrome(string s) {
        
        string rev=s;
        reverse(rev.begin(), rev.end());
        
        int n=s.length();
        int m=rev.length();
        
         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
      //finding LCS
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
                    dp[i][j]=0;
                }
            }
        }
        
      //finding max from dp table
        int maxi= INT_MIN;
        int ii=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(dp[i][j]>maxi and (i-dp[i][j]==n-j))
                {
                    maxi=dp[i][j];
                    ii=i;
                }
            }
        }
        
      //concatenating into answer
        string ans="";
        while(maxi--)
        {
            ans+=s[ii-1];
            ii--;
        }
        
        return ans;
    }
};

// Expand From Centre [sol-2]
class Solution {
public:
    int ExpandAroundCentreLen(string str , int L , int R)
    {
    
        while(L>=0 and R<str.length() and str[L]==str[R])
        {
            L--, R++;
        }
        
        return R-L-1;
    }
    
    string longestPalindrome(string str) {
      
        int len=str.length(), lenmax=0;
        
        if(len<1) return "";
        if(len==1) return str;
        
        int s =0 , e=0;
        
        for(int i=0;i<len;i++)
        {
            int maxlen1=ExpandAroundCentreLen(str,i,i);
            int maxlen2=ExpandAroundCentreLen(str,i,i+1);
            
            if(lenmax < max(maxlen1,maxlen2))
            {
                lenmax=max(maxlen1,maxlen2);
                s=i-(lenmax-1)/2;
               
            }
        }
        
    
    return str.substr(s,lenmax);    
        
    }
};

