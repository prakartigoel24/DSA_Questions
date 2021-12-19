
//link: https://leetcode.com/problems/reverse-linked-list/
class Solution {
public:
    ListNode* newHead;
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL)
            return head;
        if(head->next==NULL)
        {
            newHead=head;
            return newHead;
        }
        
        reverseList(head->next);
        
        ListNode* temp=head->next;
        temp->next=head;
        head->next=NULL;
       
        return newHead;
        
    }
};
