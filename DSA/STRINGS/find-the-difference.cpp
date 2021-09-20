//LINK: https://leetcode.com/problems/find-the-difference/

//using XOR operator
class Solution {
public:
    char findTheDifference(string s, string t) {
        
        if(s.empty())
            return t[0];

        char xo=0;
        for(int i=0, j=0;i<s.size(),j<t.size();i++,j++)
        {
            xo=xo^s[i];
            xo=xo^t[j]; 
        }
        return xo;
    }
};


//by subtracting sum of one string from another string

class Solution {
public:
    char findTheDifference(string s, string t) {
        
        if(s.empty())
            return t[0];

        int xo=0,xo2=0;
        int i=0;
        for(i=0;i<s.size();i++)
        {
            xo=xo+s[i];
            xo2=xo2+=t[i];
           
        }
        
        xo2+=t[i];
        return (char)(abs(xo-xo2));
    }
};
