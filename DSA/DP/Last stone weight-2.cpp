//LINK : 

// TABULATION
//*Variation of subset sum equals target* --> used the last row of dp array to find different subset sums then found the min difference of subsets.

class Solution {
public:
 int lastStoneWeightII(vector<int>& nums) {
       
        int n = nums.size();
        int sum=0;
     
        for(auto &it: nums)
            sum+=it;
        
      vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        
        if(nums[0]<=sum) dp[0][nums[0]]=true;
        
        for(int i=0;i<n;i++) dp[i][0]=true;
        
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                
                bool notTake=dp[i-1][j];
                bool take=false;
                if(nums[i]<=j)
                {
                    take=dp[i-1][j-nums[i]];
                }
                
                dp[i][j]=take|notTake;
                
            }
        }
        
        int mini=INT_MAX;
        for(int i=0;i<=sum/2;i++)
        {
            if(dp[n-1][i]==true)
            {
                mini=min(mini,(sum-i)-i);
            }
        }
        
        return mini;
    }
};
