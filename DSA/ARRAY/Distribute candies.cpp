//LINK : https://leetcode.com/problems/distribute-candies/

//Using set
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        unordered_set<int> s;
        int n=candyType.size(); 
        
        for(auto it:candyType)
        {
            s.insert(it);
        }
        
        int types=s.size();
        
       return n/2 <types ? n/2:types;   
    }
};

