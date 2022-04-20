// LINK : https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/

//SOL-1

class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n =nums.size();
        int ops=0;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i] <= nums[i-1])
            {
                ops+= abs(nums[i]-nums[i-1])+1;
                nums[i]=nums[i-1]+1;
            }
        }
        
        return ops;
    }
};
