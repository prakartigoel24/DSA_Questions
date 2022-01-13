//LINK : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

//Approach -1
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        
        int buy=0, sell=0, totProfit=0;
        
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i] >  arr[i-1])
                sell++;
            else
            {
                totProfit+=(arr[sell]-arr[buy]);
                buy=sell=i;
            }
        }
        
        totProfit+=(arr[sell]-arr[buy]);
        
        return totProfit;
        
    }
};

//Approach-2

class Solution {
public:
    int maxProfit(vector<int>& arr) {
        
        int totProfit=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i]< arr[i+1])
            totProfit+=(arr[i+1]-arr[i]);
        
        }
        
        return totProfit;
        
    }
};
