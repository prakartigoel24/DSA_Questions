//LINK: https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pat, string s) {
    
        string ans="";
        vector<string> v;
        int i=0;
        while (i<s.size())
        {
            if(s[i]==' ')
            {
               v.push_back(ans); 
                ans="";
            }
            else
                ans+=s[i];
            
            i++;
            
        }
        v.push_back(ans);
        
        if(pat.size()!=v.size()) return false; 
        
   
        unordered_map<char, string> mp; 
        set<string> ss;
        
       for(int i=0;i<pat.size();i++)
        {
            
            if(mp.count(pat[i]))
            {
                if(mp[pat[i]]!=v[i]) return false;
            }
            
            else if(ss.count(v[i])) return false ;
                            
            else
            {
                
                mp[pat[i]]=v[i];
                ss.insert(v[i]);
            }
        
        }
       
       return true;
        
        
    }
};
