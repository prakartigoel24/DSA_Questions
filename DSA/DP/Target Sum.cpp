//LINK : https://leetcode.com/problems/target-sum/

//MEMOISATION 

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
