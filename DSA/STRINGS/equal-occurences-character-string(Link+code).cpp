//Link : "https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/submissions/"


class Solution {
public:
    bool areOccurrencesEqual(string s) {
        
        unordered_map<char, int > mp;
        
        for(auto i : s)
        {
            mp[i]++;
        }
        
         int freq=mp[s[0]];
        
        for(auto i:s)
        {
           if(freq != mp[i])
           {
               return false;
           }
        }
        
        return true;
    }
};