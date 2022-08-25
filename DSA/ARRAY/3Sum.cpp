// LINK : https://leetcode.com/problems/3sum/

//Using 2 pointer approach 
class Solution { 
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int a, b, c;
        
        for(a = 0; a< n-2;a++)
        {
            if(a==0 or (a>0 and nums[a]!=nums[a-1]))
            {
                b=a+1 , c = n-1;
                while(b<c)
                {
                    if(nums[b]+nums[c] == -nums[a])
                    {
                        vector<int> v;
                        v.push_back(nums[a]);
                        v.push_back(nums[b]);
                        v.push_back(nums[c]);
                        ans.push_back(v);

                        while(b < c and nums[b]==nums[b+1])
                            b++;
                        while(b < c and nums[c]==nums[c-1])
                            c--;
                        
                        b++, c--;
                    }
                    else if(nums[b]+nums[c] < -nums[a])
                    {
                        b ++ ;
                    }
                    else
                        c--;
                }   
            }
            
        }
        
       return ans;
    }
};
