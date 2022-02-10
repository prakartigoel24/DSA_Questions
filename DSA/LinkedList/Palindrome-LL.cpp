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

//USING REVERSE POINTERS [sol-1]
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

//USING ARRAY (OPTIMISED ) [sol-2]

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        int N= 10e5;
        int arr[N];
        int i=0;
        while(head!=nullptr)
        {
            arr[i++]=head->val;
            head=head->next;
        }
        
        for(int j=0;j<i/2;j++)
        {
            if(arr[j]!=arr[i-j-1]) return false;
        }
        
        return true;
    }
};


//Using STACK AND QUEUE [sol-3]

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        stack<int> st ;
        queue<int> q;
        while(head!=nullptr)
        {
            st.push(head->val) , q.push(head->val);
            head=head->next;
        }
        
        while(!st.empty() and !q.empty())
        {
            if(st.top()!=q.front()) return false;
            
            st.pop();q.pop();
        }
        return true;
    }
};

