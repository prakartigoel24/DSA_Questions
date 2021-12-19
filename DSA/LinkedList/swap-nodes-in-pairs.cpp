
//LINK: https://leetcode.com/problems/swap-nodes-in-pairs/
//Recursive solution

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL or head->next==NULL)
        {
            return head;
        }
        
        if(head->next->next==NULL)
        {
            ListNode* temp=head->next;
            temp->next=head;
            head->next=NULL;
            head=temp;
            return head;
        }
        
        ListNode* temp=head->next;
        ListNode* newHead=swapPairs(head->next->next);
        
            head->next=newHead;
            temp->next=head;
            head=temp;
        
    
        
        return head;
        
    }
};
