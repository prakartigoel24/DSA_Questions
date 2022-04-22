// LINK : https://leetcode.com/problems/maximum-units-on-a-truck/

//solution 
class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), comp);
        
        int n = boxTypes.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(truckSize >= boxTypes[i][0])
            {
                ans += boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }
            else
            {
                ans += truckSize * boxTypes[i][1];
                break;
            }
        }
        
        return ans;
    }
};
