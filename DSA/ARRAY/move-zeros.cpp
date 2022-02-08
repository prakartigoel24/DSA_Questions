

//Link: https://leetcode.com/problems/move-zeroes/

//Solution-1
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     
for (int lastNonZeroele = 0, cur = 0; cur < nums.size(); cur++) {
    
    
        if (nums[cur] != 0) 
        {
            swap(nums[lastNonZeroele++], nums[cur]);
        }
    
        
}  
        
        
    }
};
