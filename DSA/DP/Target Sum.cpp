//LINK : https://leetcode.com/problems/target-sum/

//RECURSIVE APPROACH
class Solution {
int ans=0;
public:
    int solve(vector<int>& nums, int i, long long  sum, int tar)
    {
        int n = nums.size();
       
        if(i==n)
        {
            if(sum==tar) 
            {
                ans++;
            }
        }
        
        else
        {
            solve(nums,i+1,sum+nums[i],tar);
            solve(nums,i+1,sum-nums[i],tar);
        }
        
           
        return ans;
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return solve(nums,0,0,target);
        
    }
};
