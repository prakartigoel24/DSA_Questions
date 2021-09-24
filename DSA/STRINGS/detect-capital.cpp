//LINK : https://leetcode.com/problems/detect-capital/

//solution- 1


class Solution {
public:
    bool detectCapitalUse(string w) {
        
        int n = w.size(); int upperletters=0;
       for(int i=0 ;i<n;i++)
       {
           if(w[i]>= 'A' and w[i]<='Z')
               upperletters++;
       }
        
        
        if(upperletters==1)
        {
            return isupper(w[0]);
        }
        
        return (upperletters==0 || upperletters==n);
     
   }
};

//solution-2

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
