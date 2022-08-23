//  LINK : https://leetcode.com/problems/powx-n/

//Brute force
class Solution {
public:
    double myPow(double x, int n) {
        
      if(n==0)
            return 1;
        else if(n>0) 
            return x * myPow(x,n-1); 
        else
            return (1/x)* myPow(x,n+1); 
    }
};

// OPTIMAL - USING BINARY EXPONENTIATION
class Solution {
public:
    double myPow(double x, int n) {
        
       double ans = 1.0;
       long long nn = n;
       if(nn<0) nn *= -1;
        
    while(nn > 0)
    {
        if(nn%2==0)
        {
            x = x*x;
            nn = nn/2;
        }
        else
        {
            ans = ans*x;
            nn = nn - 1;
        }
    }
      
   if(n < 0) return 1.0/ans;

  return ans;
        
    }
};
