//LINK : https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
public:
    bool validPalindrome(string s) {
        
       int l =0; int r= s.length()-1;
       while (l<r)
       {
           
             if(s[l]!=s[r])
            {
                return(palinOrNot(s,l+1,r) || palinOrNot(s,l ,r-1));
            }
           l++, r--;  
       }
        return true;
    }
    
    
     bool palinOrNot(string s, int l , int  r)
    {
        while(l<r)
        {
            if(s[l++]!=s[r--])
                return false;
        }
        return true ;
    }
};
