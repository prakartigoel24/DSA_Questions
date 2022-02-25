// LINK :https://leetcode.com/problems/search-in-rotated-sorted-array/

//USING STL [sol-1]
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        auto it = find(nums.begin(),nums.end(),target);
        
        if(it!=nums.end()) return it-nums.begin();
        else return -1;
        
    }
};

//using Modified Binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        
        int n=nums.size();
        
        int s =0 , e=n-1;
        
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            
            if(nums[mid]==target) return mid;
            
            else if(nums[s]<=nums[mid])
            {
                if(target >=nums[s] and target<= nums[mid])
                {
                    e=mid-1;
                }
                else 
                {
                    s=mid+1;
                }
            }
            else if(nums[e]>=nums[mid])
            {
                if(target <=nums[e] and target>= nums[mid])
                {
                    s=mid+1;
                }
                else
                {
                    e=mid-1;
                }
            }
        }
        return -1;
    }
};




