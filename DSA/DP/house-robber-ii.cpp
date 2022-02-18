//LINK : https://leetcode.com/problems/house-robber-ii/

//Tabulation -Space Optimised

   int robhouse(vector<int>& nums) {
        
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
    
int rob(vector<int>& nums) {
        
        int n=nums.size();

        if(n==0) return 0;
        if(n==1) return nums[0];
        
    vector<int> nums0 ;
    vector<int> nums1;
    
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        {
            nums1.push_back(nums[i]);
        }
        
        if(i!= n-1)
        {
            nums0.push_back(nums[i]);
        }
    }
        return max(robhouse(nums0), robhouse(nums1));
        
    }
};

//Tabulation

class Solution {
int dp[105];
public:
    int robhouse(vector<int>& nums)
    {
        
        int n=nums.size();
       
        dp[n]=0;
        dp[n-1]=nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
         dp[i]=max(nums[i] + dp[i+2],dp[i+1]);
        }
        
        return dp[0];
    }
    
    
int rob(vector<int>& nums) {
        
        int n=nums.size();
        memset(dp,-1,sizeof(dp));

        if(n==0) return 0;
        if(n==1) return nums[0];
        
    vector<int> nums0 ;
    vector<int> nums1;
    
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        {
            nums1.push_back(nums[i]);
        }
        
        if(i!= n-1)
        {
            nums0.push_back(nums[i]);
        }
    }
        return max(robhouse(nums0), robhouse(nums1));
        
    }
};
