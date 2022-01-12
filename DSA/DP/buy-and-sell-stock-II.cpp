//LINK : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

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
