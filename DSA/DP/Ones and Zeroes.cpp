//LINK : https://leetcode.com/problems/ones-and-zeroes/

//Memoisation 

class Solution {
int dp[650][105][105];
public:
    
    int fun(vector<string>& strs,int i, int m, int n)
    {
        
        char z='0', o='1';
        int zeros = count(strs[i].begin(), strs[i].end(),z);
        int ones = count(strs[i].begin(), strs[i].end(),o);

        if(i==strs.size()-1)
        {
            if(zeros<=m and ones<=n) return  1;
            else
                return  0;
        }
    
        if(dp[i][m][n]!=NULL) return dp[i][m][n];


        int pick =INT_MIN , notpick=INT_MIN;
        
        if(zeros<=m and ones<=n)
        pick= 1+ fun(strs, i+1,m-zeros, n-ones);
        notpick=fun(strs,i+1,m,n);
        
        return dp[i][m][n]=  max(pick,notpick);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        memset(dp,NULL,sizeof(dp));
        int ans= fun(strs, 0, m, n);
        return ans;
    }
};
