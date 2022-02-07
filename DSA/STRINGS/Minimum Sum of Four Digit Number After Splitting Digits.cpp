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

//Sol-2
class Solution {
public:
    int minimumSum(int num) {
        
    int arr[4],i=0, new1=0, new2=0;
        
        while(num!=0){
            arr[i]=num%10;
            num=num/10;
            i++;
        }
        
        sort(arr, arr+4);
        new1 = arr[0]*10 +arr[2];
        new2 = arr[1]*10 +arr[3];
        return new1 + new2;
        
        
    }
};
