//Link : https://leetcode.com/problems/repeated-substring-pattern/

//without kmp(knuth-morris-pratt algorithm)

class Solution {
public:
    bool validsubstr(string &s, string &substr)
        {
             int slen=s.length();
             int substrlen=substr.length();
            
            if(slen%substrlen!=0) return false;
            
            for(int i=1;i<slen;i++)
            {
                if(s[i]!=substr[i%substrlen])return false;
            }
            return true;
        }
        
    
    bool repeatedSubstringPattern(string s) {
        
        int slen=s.length();
        int substrlen=0;
        
        if(slen<=1)return false;
        
        string substr="";
        
        for(int i=0;i< (slen>>1) ;i++)
        {
            substr+=s[i];
            
            if(validsubstr(s,substr)) return true ;
        }
        
    return false;
    }
};

// *with kmp* 

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int len=s.length();
        unordered_map<int, int > mp;
        
        if(len<=1)return false;
        int i=0 ,j=1;
        mp[0]=0;
        
        while (j<len)
        {
            if(s[i]==s[j])
            {
                mp[j++]=i+1;
                i++;
            }
            else
            {
                if(i!=0) 
                    i=mp[--i];
                else{
                      mp[j++]=0;  
                }
               
            }
        }
         

        if(len%(len-mp[len-1])==0 && (len-mp[len-1])!=len)
        {
            return true ;
        }
        else
            return false;

    }

};


