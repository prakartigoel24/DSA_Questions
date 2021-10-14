//LINK : https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* &head) {
        
    if(head==NULL || head->next == NULL) return head;
      ListNode* prev=NULL;
      ListNode* curr=head;
      ListNode* nxt= curr->next;
        
        while(curr!=NULL)
        {
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if(curr!=NULL)
                nxt=curr->next;
            else
                break;
        }
        
        return prev;
    }
};
