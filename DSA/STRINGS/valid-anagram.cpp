//Link : https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length())
            return false;
        
        unordered_map<char, int> mp;
        for(auto it : s)
        {
            mp[it]++;
        }
        
        for(auto i : t)
        {
            mp[i]--;
        }
        
        for(auto p: mp)
        {
            if (p.second!=0)
                return false;
        }
        
        return true;
    }
};
