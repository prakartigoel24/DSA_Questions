// Link  : https://leetcode.com/problems/longest-substring-without-repeating-characters/

//Optimal - 1
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        
        int n =str.length();
        
        if(n<=1) return n;
        int maxi = INT_MIN, r=0, l=0, range=0;
        unordered_set<int> s;
        
        while(r < n)
        {
            if(s.find(str[r])!=s.end())
            {
                while(l<r and s.find(str[r])!=s.end())
                {
                    s.erase(str[l]);
                    l++;
                }
            }
            s.insert(str[r]);
            range = r-l+1;
            maxi = max(maxi, range);
            
            r++;
            
        }
    
        return maxi;
    }
};

// Brute force 
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        
        int n =str.length();
        
        if(n<=1) return n;
        int maxi = INT_MIN, len =0 ;
        for(int i=0;i<n;i++)
        {
            unordered_set<char> s;
            for(int j=i;j<n;j++)
            {
                len = j-i;
                if(s.find(str[j])!=s.end())
                {
                    maxi = max(maxi,len);
                    break;
                }   
                
                maxi = max(maxi, len+1);
                s.insert(str[j]);
            }
        }
        return maxi;
    }
};
