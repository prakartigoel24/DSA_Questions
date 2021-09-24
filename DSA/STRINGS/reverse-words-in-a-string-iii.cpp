//LINK : https://leetcode.com/problems/reverse-words-in-a-string-iii/

//solution-1 ( optimised )

class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        
        for(int i = 0; i <= s.length(); ++i){
            
            if(i == s.length() || s[i] == ' ')
            {
                reverse(&s[start], &s[i]);   //reverisng the characters in place using reverse function
                front = i + 1;
            }
            
        }
        
        return s;
    }
};


//solution-2

class Solution {
public:
    string reverseWords(string s) {
     
        vector<string> v;
        string w;
        stringstream ss(s);   //using stringstream
        while (ss>>w)
        {
            reverse(w.begin(), w.end());
            v.push_back(w);
        }
   
       s=v[0];
            
        for(int i=1;i<v.size();i++)
        {
            
            s=s + " " + v[i];
            
        }
        
    return s;
        
    }
};
