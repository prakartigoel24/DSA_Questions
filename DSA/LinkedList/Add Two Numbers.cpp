// Link  :  https://leetcode.com/problems/add-two-numbers/

// Solution
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* newNode = new ListNode(-1);
        ListNode* newHead = newNode;
        int sum = 0, carry=0;
        while(l1!=NULL and l2!=NULL)
        {
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            int nodeVal = sum%10;
            ListNode* temp = new ListNode(nodeVal);

            newNode->next = temp;
            newNode = newNode->next;
            l1=l1->next;
            l2=l2->next;
            
        }
        
        while(l1!=NULL)
        {
            sum = l1->val +carry;
            carry = sum/10;
            int nodeVal = sum%10;
            ListNode* temp = new ListNode(nodeVal);

            newNode->next = temp;
            newNode = newNode->next;
            l1=l1->next;
            
        }
        
        while(l2!=NULL)
        {
            sum = l2->val +carry;
            carry = sum/10;
            int nodeVal = sum%10;
            ListNode* temp = new ListNode(nodeVal);

            newNode->next = temp;
            newNode = newNode->next;
            l2=l2->next;
        }
        
        if(carry)
        {
            ListNode* temp = new ListNode(carry);

            newNode->next = temp;
        }
        return newHead->next;
        
    }
};
