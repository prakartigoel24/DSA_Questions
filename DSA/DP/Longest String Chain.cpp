//LINK : https://leetcode.com/problems/longest-string-chain/

class Solution {
public:
    
    bool compstrings(string &s1,string &s2)
    {
        int len1=s1.length(), len2=s2.length();
        
        if(len1 != len2+1)
            return false;
        
        int i=0,j=0;
        
        while(i<len1 )
        {
            if(s1[i]==s2[j])
            {
                i++, j++;
            }
            else
            {
                i++;
            }
        }
        
        if(i==len1 and j==len2) return true;
        else return false;
        
    }
    
  static  bool func(string &s1,string &s2)
    {   
        return s1.length()< s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), func);

        int n = words.size();
        vector<int> dp(n, 1);
        int maxi=1; 

        for(int i=1;i<n;i++)
        {
            for(int prev = 0 ; prev < i ; prev++)
            {
                if(compstrings(words[i], words[prev]) and dp[i] < dp[prev]+1)
                {
                    dp[i]=dp[prev]+1;
                }
            }
            
            if(dp[i] > maxi)
            {
                maxi = dp[i];
            }
        }
        
   return maxi;
    }
};
