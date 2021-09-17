//LINK : https://leetcode.com/problems/third-maximum-number/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long max1=LONG_MIN,max2=LONG_MIN,max3=LONG_MIN;
        
        for(int n: nums)
        {
            
            if(n==max1 || n==max2 || n==max3)
                continue;
            
            if(n>max1)
            {
                max3=max2;
                max2=max1;
                max1=n;
            }
            else if(n>max2 )
            {
                max3=max2;
                max2=n;
            }
            else if(n>max3)
            {
                max3=n;
            }
           
        }
        
        if(max3!=LONG_MIN)
            return max3;
   
return max1;
        
     
    }
};
