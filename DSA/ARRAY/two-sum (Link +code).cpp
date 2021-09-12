
//LINK : https://leetcode.com/problems/two-sum/



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> v;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            int diff=target-nums[i];
                
            if(v.find(diff)!=v.end())
            {
                
                ans.push_back(v[diff]);
                 ans.push_back(i);
                return ans;
            }
            
        else
            v[nums[i]]=i;
        }
        
       
       
    return ans;
            
        
      
    }
};