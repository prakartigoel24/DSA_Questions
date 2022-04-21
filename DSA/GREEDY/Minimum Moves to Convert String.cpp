// LINK : https://leetcode.com/problems/minimum-moves-to-convert-string/

//SOL-1 
class Solution {
public:
    int minimumMoves(string s) {
        
        int n=s.size();
        int ans = 0;
        
        
        for(int i=0;i<n;)
        {
            if(s[i]=='X')
            {
                ans+=1;
                i+=3;
            }
            else i++;
        }
        
        return ans;

    }
};
