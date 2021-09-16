//Link:  https://leetcode.com/problems/array-partition-i/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int mn=0;

        for(int i=0;i<nums.size();i+=2)
        {
            
             mn+=nums[i];
            
        }
        
        return mn;
        
        
    }
};
