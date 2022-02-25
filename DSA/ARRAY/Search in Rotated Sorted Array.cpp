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

