//LINK : https://leetcode.com/problems/matrix-cells-in-distance-order/

//using multiset
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int r, int c) {
        
        int n = rows*cols;
        multiset< pair< int , vector<int> > > mp;
         vector<vector<int>> ans;
        vector<int> v;
        
        for(int i=0;i<rows;i++)
        {
            v.clear();
            for(int j=0;j<cols;j++)
            {
                int dist=abs(r-i)+abs(c-j);
                v.push_back(i);
                v.push_back(j);
                mp.insert(make_pair(dist,v));
                v.clear();
            }
            
        }
        for(auto it: mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};


//using multimap
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int r, int c) {
        
        multimap< int , vector<int> >  mp;
         vector<vector<int>> ans;
        
        for(int i=0;i<rows;i++)
        {
    
            for(int j=0;j<cols;j++)
            {
                int dist=abs(r-i)+abs(c-j);
                mp.insert({dist,{i,j}});
            }
            
        }
        for(auto it: mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
