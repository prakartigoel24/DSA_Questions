//LINK : https://leetcode.com/problems/longest-increasing-subsequence/ 

//TABULATION [Sol-1]
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n= nums.size();
        vector<int> dp (n,INT_MIN);
        dp[0]=1;
        
        int maxi=0 , ans=1;
        for(int i=1;i<n;i++)
        {
             maxi=0;
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j])
                {
                    maxi=max(maxi,dp[j]);
                }
            }
            dp[i]=maxi+1;
            
           ans= max(ans, dp[i]);
        }
    
        return ans;
    }
};
