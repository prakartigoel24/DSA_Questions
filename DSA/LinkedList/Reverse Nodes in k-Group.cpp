// LINK : https://leetcode.com/problems/reverse-nodes-in-k-group/

//Recursive solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* prev = NULL, *curr=head, *nxt , *dum = head;
        int count = 0;
        
       while(dum!=NULL) 
       {
           count++;
           dum=dum->next;
       }
        
        if(count < k) return head;
        else
            count=0;
        
        while(curr!=NULL and count < k)
        {
            nxt = curr->next;
            curr->next = prev;
            prev=curr;
            curr=nxt;
            count++;
        }

        if(nxt!=NULL)
         head-> next = reverseKGroup(nxt,k);

              
        return prev;
        
    }
};

//Iterative solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *dum = new ListNode(-1);
        dum->next = head;
        ListNode* pre = dum, *curr=dum, *nxt=dum;
        int count = 0;
        
       while(curr->next!=NULL) 
       {
           count++;
           curr=curr->next;
       }
        
   while(count>=k)
   {
       curr = pre->next;
       nxt = curr->next;
       
       for(int i=1;i<k;i++) //k-1 ops for reversing k-1 links
       {
           curr->next = nxt->next;
           nxt->next = pre->next;
           pre->next = nxt;
           nxt = curr->next;
       }
       
       count-=k;
       pre=curr;
   }
        
        return dum->next;
    }
};
