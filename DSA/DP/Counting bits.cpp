//LINK : https://leetcode.com/problems/counting-bits/

// Using built-in function
class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> v;
        for (int i = 0; i <= n; i++)
        {
            int x = __builtin_popcount(i);
            v.push_back(x);
        }
        return v;
    }
};

//Using DP table 
class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> dp(n+1,0);
        int x=1;
        for (int i = 1; i <= n; i++)
        {
           if(x*2==i)
               x*=2;
            
            dp[i]=1+dp[i-x];
        
        }
        return dp;
    }
};
 
//USING EVEN ODD PROPERTY OF BINARY NUMBERS
class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> dp(n+1,0);
        for (int i = 1; i <= n; i++)
        {
            
            dp[i]=dp[i/2] + i%2;
        
        }
        return dp;
    }
};
 
