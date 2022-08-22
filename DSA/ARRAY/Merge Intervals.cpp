// LINK : https://leetcode.com/problems/merge-intervals/

//  Using new Merged vector
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        int n = intervals.size(), s=1;
        
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=merged[s-1][1])
            {
                merged[s-1][1]= max(intervals[i][1],merged[s-1][1]);
            }
            else
            {
                merged.push_back(intervals[i]);
                s++;
            }
        }
        
        return merged;
    }
};
