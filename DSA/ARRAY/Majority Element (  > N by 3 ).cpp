// LINK : https://leetcode.com/problems/majority-element-ii/

//Optimal - Extended Moore's voting algo

//Brute force  
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto it: nums)
        {
            mp[it]++;
        }
        
        vector<int> ans;
        for(auto it:mp)
        {
            if(it.second > n/3)
            {
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};
