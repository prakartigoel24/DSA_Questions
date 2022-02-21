// Link : https://leetcode.com/problems/dungeon-game/

//Memoisation

class Solution {
int dp[201][201];
public:
    int minHp(vector<vector<int>>& dun ,int i, int j)
    {
        
        int r=dun.size();
        int c=dun[0].size();
        
        if(i>=r or j>=c) return 1e9;
        if(i==r-1 and j==c-1)
        {
            if(dun[i][j] >= 0 )
            {
                return 1;
            }
            else
            {
                return -dun[i][j]+1;
            }
        }
        
        if(dp[i][j]!=NULL) return dp[i][j];
        int right=INT_MAX, down=INT_MAX;
        
         right= minHp(dun,i,j+1);
         down =minHp(dun,i+1,j);
        
        int ans=min(right, down) - dun[i][j];
        
        
        if(ans<=0)
            return dp[i][j]= 1;
        else 
            return dp[i][j]= ans;

    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        memset(dp,NULL, sizeof(dp));
       return minHp(dungeon,0,0);
        
    }
};
