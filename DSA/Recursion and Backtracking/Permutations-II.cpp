// LINK  : https://leetcode.com/problems/permutations-ii/


class Solution {
public:
    vector<vector<int>> solve(vector<int>& nums, vector<vector<int>> &ans, int ind )
    {
        if(ind >= nums.size())
        {
            ans.push_back(nums);
            return ans;
        }
        
        unordered_set<int> s; //To avoid duplicates
        for(int i=ind;i<nums.size();i++)
        {
            if(s.find(nums[i])!=s.end()) continue; // if duplicate -> skip
            s.insert(nums[i]);
            
            swap(nums[ind],nums[i]);
            solve(nums, ans,ind+1);
            swap(nums[ind],nums[i]);
            
        }
        return ans;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        return solve(nums, ans, 0);
    }
};
