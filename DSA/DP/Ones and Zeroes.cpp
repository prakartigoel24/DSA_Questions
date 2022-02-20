//LINK : https://leetcode.com/problems/ones-and-zeroes/

 ** // scroll down for most optimal solution //**
     
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

//Tabulation
class Solution {
public:  
    int findMaxForm(vector<string>& strs, int m1, int n1) {
        
        int sz= strs.size();
        int dp[sz+1][m1+1][n1+1];
        memset(dp,0,sizeof(dp));  
        
        for(int i=0;i<=m1;i++)
        {
            for(int j=0;j<=n1;j++)
            {
                char z='0', o='1';
                int zeros = count(strs[sz-1].begin(), strs[sz-1].end(),z);
                int ones = count(strs[sz-1].begin(), strs[sz-1].end(),o);
                
                if(zeros<=i and ones<=j)
                dp[sz-1][i][j]=1;
                
            }
        }
        
        for(int i=sz-2;i>=0;i--)
        {
            
            for(int m=0;m<=m1;m++)
            {
                for(int n=0;n<=n1;n++)
                {
                    char z='0', o='1';
                    int zeros = count(strs[i].begin(), strs[i].end(),z);
                    int ones = count(strs[i].begin(), strs[i].end(),o);
                    
                    if(zeros<=m and ones<=n)
                    {
                        dp[i][m][n]=  max(dp[i+1][m-zeros][n-ones]+1 ,dp[i+1][m][n] );
                    }
                    else
                    {
                        dp[i][m][n]= dp[i+1][m][n] ;
                    }

                }
            }
        }
      
        return dp[0][m1][n1];
   
    }
};

//Space Optimised Solution

class Solution {
public:  
    int findMaxForm(vector<string>& strs, int m1, int n1) {
        
        int sz= strs.size();
        
        vector<vector<int>> cur(m1+2,vector<int>(n1+2,0));
        vector<vector<int>> next(m1+2,vector<int>(n1+2,0));
        
        for(int i=0;i<=m1;i++)
        {
            for(int j=0;j<=n1;j++)
            {
                char z='0', o='1';
                int zeros = count(strs[sz-1].begin(), strs[sz-1].end(),z);
                int ones = count(strs[sz-1].begin(), strs[sz-1].end(),o);
                
                if(zeros<=i and ones<=j)
                next[i][j]=1;
                
            }
        }
        
        for(int i=sz-2;i>=0;i--)
        {
            
            for(int m=0;m<=m1;m++)
            {
                for(int n=0;n<=n1;n++)
                {
                    char z='0', o='1';
                    int zeros = count(strs[i].begin(), strs[i].end(),z);
                    int ones = count(strs[i].begin(), strs[i].end(),o);
                    
                    if(zeros<=m and ones<=n)
                    {
                        cur[m][n]=  max(next[m-zeros][n-ones]+1 ,next[m][n] );
                    }
                    else
                    {
                        cur[m][n]= next[m][n] ;
                    }

                }
            }
            
            next=cur;
        }
        return next[m1][n1];
    }
};
