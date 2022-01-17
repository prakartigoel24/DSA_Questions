//LINK : https://leetcode.com/problems/climbing-stairs/

//SPACE OPTIMAL - [O(1)]

class Solution {
public:
    int climbStairs(int n) {
        
        if(n==0) return 0;
        int next=1;
        int next2=0;
        
        for(int i=n-1;i>=0;i--)
        {
            int ans=next2+next;
            
            next2=next;
            next=ans;
        }
        return next;
    }
};

//MEMOISATION
class Solution {
int dp[46];
public:
    int climbAns(int i, int n)
    {
        if(i==n) return 1;
        if(i>n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int ans1=climbAns(i+1,n);
        int ans2=climbAns(i+2,n);
        
        return dp[i]= ans1+ans2;
    }
    int climbStairs(int n) {
        
        memset(dp,-1,sizeof(dp));
        
        if(n==0) return 0;
        return climbAns(0,n);
    }
};

//TABULATION
class Solution {
public:
    int climbStairs(int n) {
        
        if(n==0) return 0;
        int dp[n+2];
        dp[n]=1;
        dp[n+1]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=dp[i+2]+dp[i+1];
        }
        return dp[0];
    }
};
