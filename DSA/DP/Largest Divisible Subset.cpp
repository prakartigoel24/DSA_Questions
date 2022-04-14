//LINK : https://leetcode.com/problems/largest-divisible-subset/

//By keeping track of last index used for LIS (longest increasing subsequence)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), hash(n), temp;
        hash[0]=0;
        int lastInd = 0, maxi = -1;

        
        for(int i=1;i<n;i++)
        {
            hash[i]=i;
            for(int prev = 0 ; prev < i ; prev++)
            {
                if(nums[i]%nums[prev]==0 and dp[i] < dp[prev]+1)
                {
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            }
            
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                lastInd = i;
            }
        }
        
        temp.push_back(nums[lastInd]);
        
        while(hash[lastInd]!=lastInd)
        {
            lastInd = hash[lastInd];
            temp.push_back(nums[lastInd]);
        }
        
        return temp;
    }
};
