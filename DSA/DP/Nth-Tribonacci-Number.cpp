//LINK : https://leetcode.com/problems/n-th-tribonacci-number/

//SPACE OPTIMISED SOLUTION
class Solution {
public:
    int tribonacci(int n) {
        
        if(n==0) return 0;
        else if(n==1 or n==2) return 1;
        
       int p1=0, p2=1, p3=1;
        
        for(int i=3;i<=n;i++)
        {
            
           int curr=p1+p2+p3;
            
            p1=p2;
            p2=p3;
            p3=curr;

        }
        
        return p3;
    }
};


//TABULATION
class Solution {
public:
    int tribonacci(int n) {
        
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<=n;i++)
        {
            if(i==0 or i==1) dp[i]=i;
            else if(i==2) dp[i]=1;
            else
            {
                dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
            }
        }
        
        return dp[n];
    }
};
