//LINK : https://leetcode.com/problems/palindrome-linked-list/

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

//USING REVERSE POINTERS
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
       ListNode* slow =head;
        ListNode* fast =head;
        ListNode* nxt;
        ListNode* prev;
        
        while(fast and fast->next)
            slow=slow->next , fast=fast->next->next;
        
        prev=slow ; slow=slow->next; prev->next=NULL; 
        while(slow)
        {
            nxt=slow->next; slow->next=prev; prev=slow; slow=nxt;
        }
        fast=head ; slow=prev;
        
        while(slow)
        {
            if(fast->val != slow->val) return false;
            
            else slow=slow->next , fast=fast->next;
        }
      return true;
    }
};

