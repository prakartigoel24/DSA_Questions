//Link: https://leetcode.com/problems/maximum-subarray/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
     int mx=INT_MIN, sum=0;
        
        for(auto it:nums)
        {
            
            sum+=it;
            
            mx=max(mx,sum);
            
            if(sum<0){
                sum=0;
            }
            
        }
        return mx;
    }
};