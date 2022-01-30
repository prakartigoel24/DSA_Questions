//LINK : https://leetcode.com/problems/target-sum/

//MEMOISATION 
class Solution {
int dp[21][1010];
public:
    int solve(vector<int>& nums, int i, int sum, int tar)
    {
        int n =nums.size();
      
        if(i==n)
        { 
            if(sum>0)
                if(dp[i][sum]!=-1) return dp[i][sum];
            
            if(sum==tar) return 1;
            else return 0;
        }

            int sum1= solve(nums,i+1,sum+nums[i],tar);
            int sum2= solve(nums,i+1,sum-nums[i],tar);
           
        if(sum>0) dp[i][sum]= sum1+sum2;
        return sum1+sum2;
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0,target);
        
    }
};

//RECURSIVE APPROACH
class Solution {
public:
    int solve(vector<int>& nums, int i, int sum, int tar)
    {
        int n =nums.size();
      
        if(i==n)
        {
            if(sum==tar) return 1;
            else return 0;
        }
        
            int sum1= solve(nums,i+1,sum+nums[i],tar);
            int sum2= solve(nums,i+1,sum-nums[i],tar);
           
        return sum1+sum2;
    }
  
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return solve(nums,0,0,target);
        
    }
};
