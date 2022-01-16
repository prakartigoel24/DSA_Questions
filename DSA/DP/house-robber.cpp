//LINK : https://leetcode.com/problems/house-robber/

//MEMOISATION
class Solution {
    int dp[102];
public:
    int maxProfit(vector<int>& nums,int i)
    {
        int n=nums.size();
      
        if(i==n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int rob, notrob;
        
         rob=nums[i] + (i < n-1 ? maxProfit(nums,i+2):0);
         notrob=0+maxProfit(nums,i+1);
            
         return dp[i]=max(rob,notrob);
        
    }
    
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        memset(dp,-1,sizeof(dp));
        return maxProfit(nums,0); 
    }
};

//TABULATION
class Solution {
    int dp[102];
public: 
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        memset(dp,-1,sizeof(dp));
       
        dp[n]=0;
        dp[n-1]=nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
                
         int rob= nums[i] + dp[i+2];
         int notrob=dp[i+1];
         dp[i]=max(rob,notrob);
        }
    
         return dp[0];
    }
};

//TABULATION-OPTIMISED

class Solution {
    int dp[102];
public: 
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        memset(dp,-1,sizeof(dp));
       
        dp[n]=0;
        dp[n-1]=nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
         dp[i]=max(nums[i] + dp[i+2],dp[i+1]);
        }
         return dp[0];
    }
};

// * MOST OPTIMAL SOLUTION * - SPACE OPTIMISED

class Solution {
public: 
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
       
        int prev2=0;
        int prev1=nums[n-1];
        int curi;
        for(int i=n-2;i>=0;i--)
        {
            curi=max(nums[i] + prev2,prev1);
            
            prev2=prev1;
            prev1=curi;
   
        }
         return curi;
    }
};



