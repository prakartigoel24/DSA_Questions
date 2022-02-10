//LINK : https://leetcode.com/problems/rotate-array/

//optimised solution(using STL reverse)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
    int i=1;
    int n=nums.size() ; 
    if(n==k or k==0) return;
        
     while(k>n)
        k=k-n;
        
    int l= n-k;
        
        reverse(nums.begin()+ l , nums.end());
        reverse(nums.begin(),nums.begin()+l);
        reverse(nums.begin(),nums.end());
    
        return;
    }
};

//Sol -2 (using extra space)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
    int i=1;
    int n=nums.size() ; deque<int> v;
    if(n==k or k==0) return;
        
     while(k>n)
        k=k-n;
        
    int l= n-k;
        
    while(k--) 
    { 
        int ele=nums[n-i];
         v.push_front(ele); i++;
    }
        
    i=0;
    while(l--)
    {
        v.push_back(nums[i]); i++;
    }
    
i=0;
for(auto it:v)
    nums[i++]=it;
     
        
return;
    }
};


