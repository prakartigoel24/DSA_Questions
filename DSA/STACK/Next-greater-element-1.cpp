//LINK: https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        map<int , int > mp;
        vector<int > v(nums1.size(),-1);
        
        stack <int> s;
        
        for(int n: nums2)
        {
            while(!s.empty() and s.top()<n)
            {
                mp[s.top()]=n;
                s.pop();
            }
            
            s.push(n);
        }
        
        
        for(int i=0;i<nums1.size();i++)
        {
            if(mp[nums1[i]])
            {
                v[i]=mp[nums1[i]];
            }
        }
        
        
        return v;
    }
};
