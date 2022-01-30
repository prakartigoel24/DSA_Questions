//LINK :  https://leetcode.com/problems/partition-equal-subset-sum/

//TABULATION
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return false;
        
        int sum=0;
        for(auto it: nums)
            sum+=it;
        
        if(sum%2!=0) return false;
        
        sum=sum/2;
        
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        
        bool ch=false;
        for(int i=0;i<=nums.size();i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j==0) dp[i][j]=true;
                else if(i==0 and j!=0) dp[i][j]=false;
                else
                {
                    dp[i][j]= dp[i-1][j];
                    if(nums[i-1] <= j)
                    {
                       ch = (dp[i-1][j-nums[i-1]]);
                    }
                    
                    dp[i][j]=(dp[i][j] | ch);
                }
            }
        }
        
        return dp[n-1][sum];
    }
};
