//LINK : https://leetcode.com/problems/pascals-triangle-ii/

//TABULATION

class Solution {
public:
    vector<int> getRow(int r) {
        
        vector<int> prev(r+1);
        for(int i=0;i<=r;i++)
        {
            vector<int> temp(i+1,0);
            for(int j=0;j<=i;j++)
            {
                if(j==0 or j==i)
                {
                    temp[j]=1;
                }
                else
                {
                    temp[j]= prev[j-1]+prev[j];
                }
                    
            }
            
            prev=temp;
        }
        
        return prev;
    }
};
