//LINK : https://leetcode.com/problems/excel-sheet-column-number/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int ans = 0;
        
        for (auto &c:columnTitle) {
            ans = ans * 26 + (c - 'A' + 1);
        }
        
      return ans;
    }
};
