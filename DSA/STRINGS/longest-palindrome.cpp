//LINK: https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
        
        if(s.size()==1)return 1 ;
        if (s.size()==2 && s[0]==s[1]) return 2 ;
        
        int ans=0;
        unordered_map<char, int> mp;
        for(auto it: s)
        {
            mp[it]++;
        }
        int odd=0,flag=0;
        
        for(auto p: mp)
        {
            int ele=p.second;
            
            if((ele%2)==0)
            {
               ans+=ele; 
                if(ans==s.size())return ans;
            }
            else
            {
                
                if(ele==1) flag=1;
                else if(ele==s.size()){return ele;}
                
                
                ans+=ele-1;
                odd++;
            }
 
        }
        
        if(flag==1|| odd==1) return ans+1;
        else return ans+1;
    }
};
