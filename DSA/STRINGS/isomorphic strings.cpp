//LINK : https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.size()!=t.size()) return false;
        
        unordered_map<char, char> mp;
        set<char> st;
        
        for(int i=0;i<s.size();i++)
        {
            char a=s[i] , b=t[i];
            
            if(mp.count(a))
            {
                if(mp[a]!=b) return false;
                    else continue ;
            }
            else 
            {
                if(st.count(b)) return false;
                
                mp[a]=b;
                st.insert(b);
            }
            
        }
        return true ;
    }
};
