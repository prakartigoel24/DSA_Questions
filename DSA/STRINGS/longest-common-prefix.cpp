//LINK : https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        
        if(str.size()==0) return "";
        string s=str[0];
        int mn=INT_MAX;
        for(int i=1;i<str.size();i++)
        {
            int f=0, st=0;
            int len=0;
            
            while (f<s.size() and st<str[i].size())
            {
                if(s[f]==str[i][st])
                    len++;
                else 
                    break;
                
                f++; st++;
                  
            }
        
            mn=min(mn, len);
            
        }
        
        return s.substr(0,mn);
    }
};
