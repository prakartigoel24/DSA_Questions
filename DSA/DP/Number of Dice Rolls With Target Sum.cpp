//LINK : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

//MEMOISATION

#define mod 1000000007
class Solution {
public:
    int waysdice(int n, int k, int target , vector<vector<int>> &dp) {
  
        if(target < n or target > n*k) return 0;
        
        if(n==1)
        {
            if( k >= target) return 1;
            else 
                return 0;
        }
        
         long long ways = 0;
        if(dp[n][target]!=-1) return dp[n][target]%mod;
     
            for(int i=1;i<=k;i++)
            {
                if(target-i < 0) break;
                
                ways+= (waysdice(n-1,k,target-i,dp))%mod;
            }
       
        return dp[n][target]= ways%mod;
    }

int numRollsToTarget(int n, int k, int target) {
               
        vector<vector<int>> dp(n+1,vector<int> (target+2,-1));
        
        return waysdice(n, k , target,dp)%mod;
    }
};
