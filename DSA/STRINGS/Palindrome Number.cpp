//LINK : https://leetcode.com/problems/palindrome-number/

// Method -1 (Converting num to string)
class Solution {
public:
    bool isPalindrome(int x) {
        
        string s=to_string(x);
        int l=s.length();
        
        for(int i=0;i<= l/2;i++)
        {
            if(s[i]!=s[l-1-i])
            {
                return false;
            }
        }
        
        return true;
            
        
    }
};

// Method -2  (Reversing the number)
class Solution {
public:
    bool isPalindrome(int x) {
        
        int num=x;
        
        long long rev=0;
        
        if(num<0) return false;
        
        while(num!=0)
        {
            int rem=num%10;
            rev= rev * 10 + rem;
            num/=10;
        }
        
        if(rev==x) return true;
        
        return false;
        
    }
};

//Method -3
 
