// Link:  https://leetcode.com/problems/single-number/


//OPTIMISED APPROACH (Using XOR)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans=0;
        for(int p: nums)
        {
           ans^=p; 
        }
        
        return ans;
        
    }
};


//Using Hashmap

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
       unordered_map<int , int> mp;
        
        for(int it:nums)
        {
            mp[it]++;
            
        }
        
        for(int i:nums)
        {
            if(mp[i]==1)
            {
                return i;
            }
        }
        
        return -1;
        
    }
};
