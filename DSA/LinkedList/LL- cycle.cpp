//LINK : https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//USING TWO POINTERS [sol-1]
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head==NULL or head->next==NULL ) return false;
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast and  fast->next!=NULL)
        {
            slow=slow->next; fast= fast->next->next;
            
            if(slow==fast) return true;
            
        }
        
        return false;
    }
};

//HASHMAP SOLUTION [sol-2]

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
       if(head==NULL or head->next==NULL ) return false;
        
       unordered_map<ListNode* , int > m;
        
        while (head!=NULL)
        {
            if(m[head]>0) return true;
            
            m[head]=1;
            head=head->next;
        }
        
        return false;
    }
};
