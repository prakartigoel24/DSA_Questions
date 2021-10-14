//LINK : https://leetcode.com/problems/middle-of-the-linked-list/
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
    ListNode* middleNode(ListNode* &head) {
        
        ListNode* he=head;
        int count=0; int i=0;
        while(he!= NULL)
        {
            count++;
            he=he->next;
        }
        
        int mid=count>>1; //dividing by 2 using binary operators
        
        while(i<mid)
        {
            i++;
            head=head->next;
        }
        
     return head;   
    }
};
