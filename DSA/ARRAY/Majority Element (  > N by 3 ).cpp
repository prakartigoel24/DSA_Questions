// LINK : https://leetcode.com/problems/majority-element-ii/

//Optimal - Extended Moore's voting algo
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        int num1= -1, num2 = -1, cnt1=0, cnt2=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==num1)
            {
                cnt1++;
            }
            else if(nums[i]==num2)
            {
                cnt2++;
            }
            else if(cnt1==0)
            {
                num1= nums[i];
                cnt1=1;
            }
            else if(cnt2==0)
            {
                num2= nums[i];
                cnt2=1;
            }
            else
            {
                cnt1--, cnt2--;
            }
            
        }
        cnt1=cnt2=0;
        for(auto it:nums)
        {
            if(it==num1)
            {
                cnt1++;
            }
            
            if(it==num2)
            {
                cnt2++;
            }
            
        }
        
        if(cnt1 > n/3) ans.push_back(num1);
        if(cnt2 > n/3) ans.push_back(num2);
        if(num1==num2) ans.pop_back();
        return ans;
    }
};


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
