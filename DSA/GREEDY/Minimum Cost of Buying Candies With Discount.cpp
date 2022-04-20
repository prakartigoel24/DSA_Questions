// LINK : https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

//SOL -1
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        sort(cost.begin(), cost.end());
        int mincost = 0 , n = cost.size();
        if(n==1) return cost[0];
        if(n==2) return cost[0]+cost[1];
            
        for(int i=n-1;i>=0;i-=3)
        {
            mincost+=cost[i];
            if(i>0) mincost+=cost[i-1];
        }
        
        return mincost;
    }
};
