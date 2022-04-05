//LINK : https://leetcode.com/problems/longest-increasing-subsequence/ 

//OPTIMISED APPROACH 
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        
        int n=arr.size(), maxi=1;
        vector<int> dp(n,1);
        
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(arr[i] > arr[prev])
                {
                    dp[i]=max(dp[i], 1+dp[prev]);
                }
            }
            
            maxi=max(maxi,dp[i]);
        }
        
        return maxi;
    }
};

//TABULATION [Sol-1]
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                int take=0 , nottake=0;

                nottake = 0 + dp[i+1][prev+1];

                if( prev == -1 || arr[i] > arr[prev] )
                {
                    take = 1 +dp[i+1][i+1];
                }

                 dp[i][prev+1]=max(take,nottake);

            }
        }
        
        
        return dp[0][0];
    }
};

//TABULATION [SOL-2]
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        
        int n=arr.size();
        vector<int> curr(n+1,0), next(n+1,0);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                int take=0 , nottake=0;

                nottake = 0 + next[prev+1];

                if( prev == -1 || arr[i] > arr[prev] )
                {
                    take = 1 +next[i+1];
                }

                 curr[prev+1]=max(take,nottake);

            }
            next=curr;
        }
        return curr[0];
    }
};
