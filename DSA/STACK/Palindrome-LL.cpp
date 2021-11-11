//LINK : https://leetcode.com/problems/palindrome-linked-list/

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

