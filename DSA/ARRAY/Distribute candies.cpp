//LINK : https://leetcode.com/problems/distribute-candies/

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        set<int> s;
        int n=candyType.size(); 
        
        for(auto it:candyType)
        {
            s.insert(it);
        }
        
        int types=s.size();
        
        if(types > n/2)
        {
            return n/2;
        }
        
        return types;
           
        
    }
};
