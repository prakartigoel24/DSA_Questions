//LINK: https://leetcode.com/problems/reverse-string/

//using recursion - method 1

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        if(s.size()<=1)
        {
            return;
        }

          char ch = s[0];
          s.erase(s.begin());
            reverseString(s);
            s.push_back(ch);
        return;
        
    }
};




