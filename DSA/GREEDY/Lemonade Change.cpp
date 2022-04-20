// LINK : https://leetcode.com/problems/lemonade-change/

//Sol -1
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int tenbills =0, fivebills=0,twentybills=0;
        bool flag=true;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
                fivebills++;
            }
            else if(bills[i]==10)
            {
                tenbills++;
                if(fivebills > 0)
                {
                    fivebills--;
                }
                else
                {
                    flag=false;
                    break;
                }
            }
            else
            {
                twentybills++;
                if(fivebills > 0 and tenbills > 0)
                {
                    fivebills--, tenbills--;
                }
                else if(fivebills >=3)
                {
                    fivebills-=3;
                }
                else
                {
                    flag=false;
                    break;
                }
                
            }
                
        }
        
        return flag;
        
    }
};
