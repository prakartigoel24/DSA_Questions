//LINK : https://leetcode.com/problems/last-stone-weight/

//Using Priority Queue [sol-1]
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
               
        priority_queue <int> pq;
        
        for(auto it:stones)
        {
            pq.push(it);
        }
        int n =pq.size() ;
        
        int fe, se;
        
        while(n > 1)
        {
            fe=pq.top();
            pq.pop();
            se=pq.top();
            pq.pop();
            
            n-=2;
            
            if(fe-se > 0)
            {
                pq.push(fe-se);
                n+=1;
            }
          
        }
        
        if(!pq.empty()) return pq.top();
        else return 0;
        
    }
};

//sol-2 (Using max heap)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
         
        int n =stones.size() ;
        make_heap(stones.begin(),stones.end());
        
        int fe, se;
        
        while(n > 1)
        {
            fe=stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            se=stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            n-=2;
            
            if(fe-se > 0)
            {
                stones.push_back(fe-se);
                push_heap(stones.begin(),stones.end());
                n+=1;
            }
          
        }        
        if(!stones.empty()) return stones.front();
        else return 0;
        
    }
};
