//link : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

//brute force

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int count=0;
        for(int i=0;i< grid.size();i++)
        {
            for(int j=0;j< grid[0].size();j++)
            {
                if(grid[i][j] < 0)
                {
                    count++;
                }
            }
        }
       
        return count;
        
        
//optimised
     
        for(auto row: grid)
        {
            int s=0 , e=row.size()-1;
            
            if(row[e] >= 0) continue; 
            if(row[s] < 0) {count+= row.size(); continue; }
            
            else
            {
                while(s<=e)
                {
                    
                    int mid=s+ (e-s)/2 ;
                    
                    if(row[mid] >= 0)
                        s=mid+1;
                    else
                        e=mid-1;
                }
                
                count+=row.size() - s;
                
            }
        }
        
        return count;

    }
};


