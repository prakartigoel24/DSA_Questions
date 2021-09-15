//LINK: https://leetcode.com/problems/next-greater-element-i/

//optimised solution using stack 

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

//****************************************************************************************************

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        map<int , int > mp;
        vector<int > v(nums1.size(),-1);
        
        for(int i=0;i<nums2.size();i++)
        {
            mp[nums2[i]]=i;
        }
        
        
        for(int j=0;j<nums1.size();j++)
        {
            int idx=mp[nums1[j]];
            
            for(int i=idx+1;i<nums2.size();i++)
            {
                if(nums2[i]>nums1[j])
                {
                    v[j]=nums2[i];
                    break;
                }
                
            }
            
             
        }
        
        
        return v;
    }
};
