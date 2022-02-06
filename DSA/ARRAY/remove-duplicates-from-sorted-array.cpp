//Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

//Method -1
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
           
        int prev=nums[0];
        int idx=1;
        

         if(nums.size()==0 || nums.size()==1)
        {
            return nums.size();
        }
        
        if(nums.size()==2 && nums[0]==nums[1])
        {
          return 1;  
        }
        

        for(int i=0;i<nums.size();i++)
        {
            
            if(nums[i]!=prev)
            {
                nums[idx]=nums[i];
                prev=nums[i];
                idx++;
            }
            
            
        }
        
        return idx;
        
    }
};
