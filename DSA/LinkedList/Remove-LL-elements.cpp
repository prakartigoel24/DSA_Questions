//LINK : https://leetcode.com/problems/remove-linked-list-elements/

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

//ONE POINTER

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head and head->val ==  val)
            head=head->next;    // when val is in starting nodes
        
        ListNode* curr=head ;
        while(curr and curr->next)
        {
            if(curr->next->val == val)
            {
                curr->next=curr->next->next;
            }
            else
                curr=curr->next;
        }
        
        return head;
        
    }
};

//Two POINTER

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head and head->val ==  val)
            head=head->next;    // when val is in starting nodes
        
        ListNode* curr=head ;
        ListNode* prev=NULL;
        
        while(curr)
        {
            if(curr->val == val)
            {
                prev->next=curr->next;
                curr=curr->next;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
                
        }
        
        return head;
        
    }
};
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
