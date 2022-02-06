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

//METHOD -2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int> s(nums.begin(), nums.end());
        
        nums.clear();
        
        for(auto it: s)
        {
            nums.push_back(it);
        }
        
        return nums.size();
    }
};

//method -3

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
       auto it =  unique(nums.begin(),nums.end());
        
        
        int  k = distance(nums.begin(), it);
        
        
        return k;
    }
};
