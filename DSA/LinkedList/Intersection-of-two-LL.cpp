//LINK :  https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode *getIntersectionNode(ListNode * headA, ListNode * headB) {
        
        int cntA=0 , cntB=0;
        ListNode* A=headA;
        ListNode* B=headB;
        
        while (headA!=nullptr)
        {
            cntA++;
            headA=headA->next;
        }
        
        while (headB!=nullptr)
        {
            cntB++;
            headB=headB->next;

        }
        
        
        int dif=0;
        
        if(cntA > cntB)
        {
            dif=cntA-cntB;
            while(dif--)
             A=A->next;
        }
        else if(cntA < cntB)
        {
            dif=cntB-cntA;
            while(dif--)
                B=B->next;
        }
    
        while (A!=nullptr and B!=nullptr)
        {
            if(A==B)
            {
                return B;
            }
            
            A=A->next;
            B=B->next;
        }
        
        return NULL;
    }
};

//USING 2 POINTERS //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    ListNode *getIntersectionNode(ListNode * headA, ListNode * headB) {
        
       ListNode * a=headA ;
        ListNode * b = headB ;
        
        while (a!=b)
        {
            if(a==nullptr)
                a=headB;
            else
                a=a->next;
            
            
            if(b==nullptr)
                b=headA;
            else
                b=b->next;
        }
        
    
        return a;
        
    }
};



//USING HASHMAP //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    ListNode *getIntersectionNode(ListNode * headA, ListNode * headB) {
        
       ListNode * a=headA ;
        ListNode * b = headB ;
        
       unordered_map<ListNode* , int > mp;
        
        while(a!=NULL)
        {
            mp[a]++;
            
            a=a->next;
        }
        
        while(b!=nullptr)
        {
            if(mp[b] > 0)
            {
                return b;
            }
            b=b->next;
        }
        
        return NULL;
        
    }
};

