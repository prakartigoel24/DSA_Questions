//Link : https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        
            
        if(s.length()==1) return 0;
        
        unordered_map<char , int > mp;
        
        for(auto p: s)
        {
            mp[p]++;
        }

         for(int i=0;i<s.length();i++)
         {
             if(mp[s[i]]==1)
             {
                 return i;
             }
         }
     
 return -1;
    }
};
