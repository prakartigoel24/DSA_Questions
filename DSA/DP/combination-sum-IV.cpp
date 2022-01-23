//LINK : https://leetcode.com/problems/combination-sum-iv/

//TABULATION
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        vector<int> dp(target+1,0);
        dp[0]=1;
        
        for(int i=1;i<=target;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(nums[j] > i) continue;
                
                dp[i] += (dp[  i - nums[j] ]%10000000007);
            }
        }
        
        return dp[target];
    }
};

//MEMOISATION
class Solution {
public:
    int solve(vector<int>& nums, int target,vector<int>& dp)
    {
        if(dp[target]!=-1) return dp[target];
        
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] >  target)
                continue;
        
            ans+=solve(nums,target-nums[i],dp);
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int>dp(target+1,-1);
        dp[0]=1;
        
        return solve(nums,target,dp);
    }
};
