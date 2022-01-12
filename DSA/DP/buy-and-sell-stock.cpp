//  LINK :https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int totProfit=0, currProfit=0,minPrice=INT_MAX;
        
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i] < minPrice)
                minPrice=prices[i];
            
            currProfit=prices[i]-minPrice;
            totProfit=max(totProfit,currProfit);
            
        }

        return totProfit;
    }
};
