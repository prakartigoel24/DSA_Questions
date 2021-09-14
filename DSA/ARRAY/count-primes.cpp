//LINK: https://leetcode.com/problems/count-primes/


// *Uses sieve of eratosthenes*

//OPTIMISED 

class Solution {
public:
    int countPrimes(int n) {
        
        vector<bool> arr(n, false);
        int ans = 0;
        for (int i = 2;i < n; i++) {
            
            if (arr[i]) continue;
            
            ans++;
            
            for (long j = (long)i * i; j < n; j += i)
                arr[j] = true;
            
        }
        return ans;
    }
};

//less optimised

class Solution {
public:
    int countPrimes(int n) {
        
        vector<int> arr(n,0);
        int snt=0;
        
        for(int i=2;i*i<n;i++)
        {
            if(arr[i]==0)
            {
                for(int j=i*i;j<n;j+=i)
                {
                    arr[j]=1;
                }
            }
        }
           
        for(int i=2;i<n;i++)
        {
            if(arr[i]==0)
            {
                snt++;
            }
        }
        if( n==2 ||n==1 || n==0)
            return 0;
        else
        return snt;
    }
};


