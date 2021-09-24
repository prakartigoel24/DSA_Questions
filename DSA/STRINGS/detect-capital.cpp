//LINK : https://leetcode.com/problems/detect-capital/

class Solution {
public:
    bool detectCapitalUse(string w) {
        
        int n = w.size();
        
        bool firstchar=isupper(w[0]);
        
        bool allupper=true , allower=true;
        
        for(int i=1;i<n;i++)
        {
            if(isupper(w[i]))
                allower=false;
            else
                allupper=false;
        }
            
        
        return ((firstchar&allupper) || allower);
        
    }
};
