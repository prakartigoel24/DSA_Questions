// LINK : https://leetcode.com/problems/trapping-rain-water/

//OPTIMAL SOLUTION *Two pointers* [TC- O(N)]
class Solution {
public:
    int trap(vector<int>& height) {
        
          int n = height.size();
          int left = 0, right = n - 1;
          int res = 0;
          int maxLeft = 0, maxRight = 0;
          while (left <= right)
          {
            if (height[left] <= height[right]) 
            {
                  if (height[left] >= maxLeft) 
                  {
                        maxLeft = height[left];
                  } 
                  else 
                  {
                        res += maxLeft - height[left];
                  }

                  left++;
            }
            else
            {
                  if (height[right] >= maxRight)
                  {
                        maxRight = height[right];
                  }
                  else 
                  {
                        res += maxRight - height[right];
                  }
                  right--;
                }
          }
        
          return res;
        
    }
};

//Precomputing left-max and right-max to optimise solution  [TC- O(3*N)]
class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int prefix[n], suffix[n];
        int sum=0;
        
        prefix[0]=height[0];
        suffix[n-1] = height[n-1];
        for(int i=1;i<n;i++)
        {
           
            prefix[i] = max(prefix[i-1],height[i]);
        }
           
        for(int i=n-2;i>=0;i--)
        {
            suffix[i] = max(suffix[i+1],height[i]);
        }
         
        for(int i=0;i<n;i++)
        {
            sum+= min(prefix[i], suffix[i]) - height[i];
        }
    
        return sum;
        
    }
};

//Finding left-max and right-max of every index to find trpped water [TC- O(N^2)]
class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            int lmax=0, rmax=0;
            for(int j=i;j>=0;j--)
            {
                lmax =max(lmax, height[j]);
            }
            
            
            for(int j=i;j<n;j++)
            {
                rmax =max(rmax, height[j]);
            }
            
            sum+= min(rmax, lmax)-height[i];
            
        }
           
    
        return sum;
        
    }
};
