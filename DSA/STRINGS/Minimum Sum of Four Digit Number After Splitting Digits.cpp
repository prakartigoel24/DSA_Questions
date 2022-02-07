//LINK : https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/

//Solution
class Solution {
public:
    int minimumSum(int num) {
        
        string str= to_string(num);
        
        vector<int> arr(4);
        for(int i=0;i<4;i++)
        {
            arr[i]=str[i]-'0';
        }
        
        sort(arr.begin(), arr.end());
        int a1=arr[0]*10+arr[3];
        int a2=arr[1]*10+ arr[2];
        
        return a1+a2;
    }
};
