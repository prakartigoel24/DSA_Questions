//Link: https://leetcode.com/problems/contains-duplicate-ii/

//optimised solution 

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        
        unordered_map<int , int > mp;
        
        
       for(int i=0;i<nums.size();i++)
       {
           
           if((mp.count(nums[i])!=0) and (abs(i-mp[nums[i]]) <= k ))
               return true ;
          
         mp[nums[i]]=i;
       
       }
        return false;
        
    }
};


// ********************************************************************************************

//less optimised solution

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        
        unordered_map<int , int > mp;
        
        
       for(int i=0;i<nums.size();i++)
       {
           
           if(mp.count(nums[i])==0)
               mp[nums[i]]=i;
           
           else 
           {
               int diff = abs(i-mp[nums[i]]);
               if (diff <= k)
                  return true ;
              
               else 
                   mp[nums[i]]=i;
               
           }
       }
        return false;
        
    }
};
