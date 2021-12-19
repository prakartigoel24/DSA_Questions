//LINK: https://leetcode.com/problems/remove-linked-list-elements/
//RECURSIVE SOL-1
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head==NULL)
        {
            return head;
        }
        if(head->next==NULL)
        {
            if(head->val!=val)
                return head;
        }

        ListNode* first=head;
        ListNode* newHead=removeElements(head->next,val);
        
        if(first->val ==  val)
        {
            return newHead;
        }
        else
        {
            first->next = newHead;
            newHead=first;
        }
        
        
        
return newHead;
    }
};

//RECURSIVE SOL-2

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head==NULL)
        {
            return head;
        }
        if(head->next==NULL)
        {
            if(head->val!=val)
                return head;
        }

        while(head and head->val ==  val)
        {
            head=head->next;
        }
        
        ListNode* first=head;  
        
        if(first!=NULL)
        first->next=removeElements(first->next,val);

        
        return first;
     
    }
};

