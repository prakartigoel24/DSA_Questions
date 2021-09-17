//Link: https://leetcode.com/problems/maximum-product-of-three-numbers/

//optimised solution


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
       
         
         long long min1=INT_MAX , min2=INT_MAX , max1=INT_MIN , max2=INT_MIN, max3=INT_MIN ;
        
        for(auto i : nums)
        {
            if (i<=min1)
            {
                min2=min1;
                min1=i;
            }
            else if(i<=min2)
            {
                min2=i;
            }
            
            if(i>=max1)
            {
                max3=max2;
                max2=max1;
                max1=i;
            }
            else if(i >= max2)
            {
                max3=max2;
                max2=i;
            }
            else if( i>= max3)
            {
                max3=i;
            }
            
        }
           
        return max(min1*min2*max1,max1*max2*max3);
    }
};


//solution2 *********************************************************************************************

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int pro1=1,pro2=1;
        int n=nums.size();
        
        
        pro1=nums[0]*nums[1]*nums[n-1];
        pro2=nums[n-1]*nums[n-2]*nums[n-3];
        
        int a =pro1>pro2 ? pro1 :pro2 ;

        return a ;
    }
};
