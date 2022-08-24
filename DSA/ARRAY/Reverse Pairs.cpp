// LINK : https://leetcode.com/problems/reverse-pairs/

//Optimal solution -Modified Merge Sort [TC -> O(NlogN) + O(N) + O(N)] 
class Solution {
public:
    int merge(vector<int>& nums, int l,int mid, int r)
    {
        int rps= 0;
        int i=l, j=mid+1;
        int k=0;
        int temp[r-l+1];
        
        int jj=mid+1;
        for(int ii=l;ii<=mid;ii++)
        {
            while(jj<=r and  (nums[ii] > 2LL* nums[jj]) )
            {
              jj++;
            }
            
            rps += (jj-mid-1);
        }
        
        while(i<=mid and j<=r)
        {
            if(nums[i] <= nums[j])
            {
                temp[k++] = nums[i++];
            }
            else
            {
                temp[k++] = nums[j++];
            }
        }
        
        while(i<=mid)
            temp[k++] = nums[i++];
            
        while(j<=r)
            temp[k++] = nums[j++];
        
        for(int i=l,k=0;i<=r;i++,k++)
            nums[i] = temp[k];
        
        return rps;
    }
    int mergesort(vector<int>& nums, int l, int r)
    {
        int rps=0;
        if(l<r)
        {
            int mid = (l+(r-l)/2);
            rps+=mergesort(nums,l,mid);
            rps+=mergesort(nums,mid+1,r);
            rps+=merge(nums,l,mid,r);
        }
        return rps;
    }
    int reversePairs(vector<int>& nums) {
    
       return mergesort(nums,0,nums.size()-1);
    }
};


//Brute force (Gives TLE and integer overflow)
 int reversePairs(vector < int > & arr) {
      int Pairs = 0;
      for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
          if (arr[i] > 2 * arr[j]) Pairs++;
        }
      }
      return Pairs;
   }

