// LINK : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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

// Using 2 pointers. [TC-O(N)]
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL) return head;
        if(head->next==NULL) 
        {
            head = head->next;
            return head;
            
        }
        
        while(n>0)
        {
            fast=fast->next;
            n--;
        }
        
        if(fast==NULL) //means we have to remove first node 
        {
            head=head->next;
            return head;
        }
        
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
        
       
    }
};


// By counting the nodes. [TC-O(2N)]
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int cnt = 0;
        ListNode* head1=head;
        ListNode* head2=head;

        while(head1!=NULL)
        {
            head1 = head1->next;
            cnt++;
        }
        
        if(n > cnt) return head;
        cnt = cnt - n;
        if(cnt==0)
        {
            head = head->next;
            return head;
        }
        
        while(cnt > 1 and head!=NULL)
        {
            head=head->next;
            cnt--;
        }
        
        head->next = head->next->next;
        
        return head2;
    }
};

