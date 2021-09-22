//LINK : https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        
        int i=a.length()-1, j=b.length()-1;
        
        int carry=0;
        string res="";
        
        while (i>=0 || j>=0 || carry>0)
        {
            if(i>=0) carry+=a[i--]-'0';  
            if(j>=0) carry+=b[j--]-'0'; 
            
                
                res=char(carry%2 + '0') + res;
                carry=carry>>1;
                
        }
       return res; 
    }
};
