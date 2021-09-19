//LINK: https://leetcode.com/problems/ransom-note/

//optimised solution


class Solution {
public:
    bool canConstruct(string r, string m) {
        
          
        int count[26] = {0};
        for(char ch : m)
            count[ch - 'a']++;
        
        for(char ch : r)
            if(count[ch - 'a']-- <= 0)
                return false;
        
        return true;
            
        
        
    }
};

//*******************************************************************************************

class Solution {
public:
    bool canConstruct(string r, string m) {
        
        if(r.length()==1 && m.length()==1 && r[0]==m[0])
            return true;
        
        unordered_map<char, int> mp;
        unordered_map<char, int> mp2;
        
        for(auto i: r)
        {
            mp[i]++;
        }
        
         for(auto j: m)
        {
            mp2[j]++;
        }
        
        for(auto it: r)
        {
            if(mp[it]<=mp2[it])
                continue;
            else
                return false;
        }
        
        return true ;
        
            
        
        
    }
};
