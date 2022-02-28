//LINK :  https://leetcode.com/problems/2-keys-keyboard/

//RECURSIVE SOLUTION - (accepted) [sol-1]
class Solution {
public:
int steps(int reqA ,int screenA,int clipA)
    {
        if(screenA==reqA or reqA==1) return 0;
        else if(reqA==2) return 2;
        else if(screenA > reqA) return 10000;
        
        long copy=INT_MAX, paste=INT_MAX;
        
        if(screenA!=clipA)
        copy= 1 + (steps(reqA , screenA , screenA));
        if(clipA > 0)
        paste= 1 +(steps(reqA, screenA+clipA,clipA));
        
        return min(copy,paste);

    }
    
int minSteps(int n) {
        
        return steps(n,1,0);
        
    }
};

//MEMOISATION SOLUTION  [sol-2]
class Solution {
int dp[1010][1010];
public:
int steps(int reqA ,int screenA,int clipA)
    {
    
        if(screenA==reqA or reqA==1)  return dp[screenA][clipA]= 0;
        else if(reqA==2) return dp[screenA][clipA]= 2;
        else if(screenA > reqA) return 10000;
    
    if(dp[screenA][clipA]!=-1) return dp[screenA][clipA];
        
        long copy=INT_MAX, paste=INT_MAX;
        
        if(screenA!=clipA)
        copy= 1 + (steps(reqA , screenA , screenA));
        if(clipA > 0)
        paste= 1 +(steps(reqA, screenA+clipA,clipA));
        
        return dp[screenA][clipA]= min(copy,paste);

    }
    
int minSteps(int n) {
        
    memset(dp,-1,sizeof(dp));
        return steps(n,1,0);
        
    }
};
