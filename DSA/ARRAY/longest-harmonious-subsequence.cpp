//Link : https://leetcode.com/problems/longest-harmonious-subsequence/

// Kind of Optimised solution 

class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        unordered_map <int , int > mp;
        int mx=INT_MIN;
        
        for ( auto p : nums)
        {
            mp[p]++;
        }
 
        
        for(int ele : nums)
        {        
             auto it = 0;
            
            if(mp[ele+1] > 0)
            {
                it = mp[ele] + mp[ele+1];
        
            }
           
            if(mp[ele]==nums.size())
            {
                it=0;
            }

            mx = max(mx, it);

        }

        return mx;
        
    }
};
