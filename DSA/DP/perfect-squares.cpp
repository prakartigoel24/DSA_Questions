//LINK : https://leetcode.com/problems/perfect-squares/

//TABULATION
class Solution {
public:
    int numSquares(int n) {
        
        if(n<=3) return n;
        
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;

        for(int i=4;i<=n;i++)
        {
            for(int j=1;j*j <=i ;j++)
            {
                dp[i]=min(dp[i],dp[i - (j*j)]);
            }
            dp[i]+=1;  
        }
        
        return dp[n];
    }
};

//Memoisation
class Solution {
int dp[10005];
public:
    int Squares(int n) {
        
        if(n<=0) return 0;
        if(n<=3) return n;
        
        if(dp[n]!=-1) return dp[n];
            
        int m=INT_MAX;
            for(int j=1;j*j <=n ;j++)
            {
                m= min(m,Squares(n - (j*j)));
            }
           
      return dp[n]=m+1;
       
    }
    
    int numSquares(int n) {
        
        memset(dp,INT_MAX,sizeof(dp));
       return Squares(n);
    }
};
