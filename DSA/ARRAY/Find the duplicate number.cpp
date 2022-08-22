// LINK : https://leetcode.com/problems/find-the-duplicate-number/

//Optimal Approach - Floyd's cycle detection  [SC- O(1)]
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
       int slow = nums[0], fast = nums[0];
        
        do
        {
            slow=nums[slow]; //moves 1 step
            fast = nums[nums[fast]]; //moves 2 steps
        
        }
        while(slow!=fast);
       
        
        fast = nums[0];
        
        while(slow!=fast)
        {
            fast = nums[fast];
            slow=nums[slow];
        }
        
        return slow;
    }
};


// Approach-  using logic of repetition and cycle [SC- O(1)]
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
       while(nums[0] !=nums[nums[0]])
       {
           swap(nums[0], nums[nums[0]]);
           
       }
        
        return nums[0];
    }
};


//Approach - using hashmap [SC- O(N)]
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        int ans;
        for(auto it:nums)
        {
            mp[it]++;
            
            if(mp[it]==2)
            {
                ans = it;
            }
        }
        
            return ans;
    }
};



