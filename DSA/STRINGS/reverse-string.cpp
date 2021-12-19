//Link : https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int n=s.size();
        if(n==1) return ;
        int i=0, j=n-1;
        
        while (i<j)
        {
            swap(s[i++], s[j--]);
        }
        return ;
    }
};


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





