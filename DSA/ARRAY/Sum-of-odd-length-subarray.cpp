//LINK : https://leetcode.com/problems/sum-of-all-odd-length-subarrays/submissions/


o(n)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        int sum=0;
        int len=arr.size();
        int st=0,en=0,tot=0,odd=0;
        
        for(int i=0;i<len;i++)
        {
            st=len-i;
            en=i+1;  // or len-st+1;
            
            tot=st*en;
            
            odd=tot/2;
            
            if(tot%2==1)
            {
                odd++;
            }
            
            sum+= odd* arr[i];
        }
       
        return sum;
        
    }
};


//solution 2 

o(n^2)
int n=arr.size(),sum=0;
        for(int i=0;i<n;i++){
            int s=0,x=0;
            for(int j=i;j<n;j++){
                s+=arr[j];
                if(x%2==0){
                    sum+=s;
                }
                x++;
            }
        }
       return sum;

