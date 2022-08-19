// LINK : https://leetcode.com/problems/permutations/

//solution 1
class Solution {
public:
    vector<vector<int>> storePermutes(vector<int>& nums, int i) {
        
        if(i == nums.size()-1)
        {
            vector<vector<int>>newP;
            newP.push_back({nums[i]});
            return newP;
        }
        
        int firstEle = nums[i];  // first element
        vector<vector<int>> perms = storePermutes(nums,i+1); // permutations from i+1 index
        vector<vector<int>>newPerms;

        for(int ii =0 ;ii < perms.size(); ii++)
        {
            for(int j = 0; j<= perms[0].size();j++)
            {
                vector<int> temp = perms[ii];
                temp.insert(temp.begin()+j,firstEle); // first element inserted in between all permutations.
                newPerms.push_back(temp);
            }
            
        }
        
        return newPerms;
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
      
        vector<vector<int>> ans = storePermutes(nums, 0);
        return ans;
        
    }
};

//Solution using swapping 
class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>> &ans, int ind )
    {
        if(ind >= nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[ind],nums[i]);
            solve(nums, ans,ind+1);
            swap(nums[ind],nums[i]);
            
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        solve(nums, ans, 0);
        return ans;
        
    }
};
