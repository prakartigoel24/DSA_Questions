//LINK : https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        if(s.length()==1) return 1 ;
        int len=s.length();
        int ans=0;
        int i=len-1;
        
        while(i>=0 && s[i]==' ')
        {
            i--;
        }

        while (i>=0 && s[i]!=' '){
            
            i--;
        ans++;
        }
        
 return ans;
    }
};
