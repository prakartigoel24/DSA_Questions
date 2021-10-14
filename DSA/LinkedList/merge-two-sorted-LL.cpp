//LINK :https://leetcode.com/problems/merge-two-sorted-lists/

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

//ITERATIVE SOLUTION

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        
        if(h1==NULL ) return h2;
        if(h2==NULL) return h1;

        ListNode* curr;
        ListNode* head;
        
        if(h1->val < h2->val)
        {
            curr=h1;
            head=h1;
            h1=h1->next;
        }
        else
        {
            curr=h2;
            head=h2;
            h2=h2->next;
        }
        
        while (h1!=nullptr and h2!=nullptr)
        {
            if(h1->val < h2->val)
            {
                curr->next=h1;
                curr=h1;
                h1=h1->next;
                
            }
            else
            {
                curr->next=h2;
                curr=h2;
                h2=h2->next;
            }
        }
        
        while(h1!=nullptr)
        {
            curr->next=h1;
            curr=h1;
            h1=h1->next;
        }
        while(h2!=nullptr)
        {
            curr->next=h2;
            curr=h2;
            h2=h2->next;
        }
        
        return head;
    }
};

//RECURSIVE SOLUTION

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* &h1, ListNode* &h2) {
        
        if(h1==NULL ) return h2;
        if(h2==NULL) return h1;
        

        if(h1->val < h2->val)
        {

            h1->next= mergeTwoLists(h1->next , h2);
            return h1;
        }
        else
        {

            h2->next= mergeTwoLists(h1, h2->next);  
            return h2;
        }
        
        
    }
};
