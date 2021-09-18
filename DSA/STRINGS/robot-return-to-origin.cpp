//LINK :https://leetcode.com/problems/robot-return-to-origin/


//you can use switch instead of if else too.

class Solution {
public:
    bool judgeCircle(string moves) {
        
        int x=0, y=0;
        for(auto i : moves)
        {
            if(i=='U')
            {
                y++;
            }
             else if(i=='D')
            {
                y--;
            }
            else if(i=='R')
            {
                x++;
            }
            else
            {
                x--;
            } 
        }
        
        return (x==0 && y==0);
        
        
    }
};
