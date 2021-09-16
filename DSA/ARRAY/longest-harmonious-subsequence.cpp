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

// solution2 ***************************************************************************************************88

class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        unordered_map <int , int > mp;
        int mx=0;
        
        for ( auto p : nums)
        {
            mp[p]++;
        }
 
        
        for(auto it : mp)
        {        
             
            int ele=(it.first+1);
            if(mp.count(ele) > 0)
            {
                auto sum=it.second + mp[ele];
                
                mx=max(mx,sum);
            }
            
        }

        return mx;
        
    }
};
