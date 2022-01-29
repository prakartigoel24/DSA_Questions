//LINK : https://leetcode.com/problems/running-sum-of-1d-array/

//APPROACH-1
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        vector<int> v;
        
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            v.push_back(sum);
        }
        
        return v;
        
        
    }
};

//APPROACH-2
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        vector<int> v;
        v.push_back(nums[0]);

        for(int i=1;i<nums.size();i++)
        {
            v.push_back(nums[i]+v[i-1]);
        }
        
        return v;
        
        
    }
};
