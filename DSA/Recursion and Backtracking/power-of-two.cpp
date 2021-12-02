//Link : https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n==1)
            return true;
        
        if(n==0 or n%2!=0)
            return false;
        
        return isPowerOfTwo(n/2);
      
    }
};
