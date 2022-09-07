// LINK : https://leetcode.com/problems/rotate-list/

//Connect the last k nodes to head
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head ==NULL or head->next==NULL or k==0) return head;
        
        ListNode* h=head , *kth=head;
        int cnt=1, n = 1;
        
        while(h->next!=NULL)
        {
            h=h->next;
            cnt++;           //size of LL
        }
        
        h->next = head;      //last node linked to first 
        
        h=kth;
        k=k%cnt; 
        cnt=cnt-k;
        
        while(n<cnt)
        {
            h=h->next;
            n++;
        }
        
        head=h->next;        // kth node made head
        h->next = NULL;     
    
        return head;
        
    }
};

//For every K , attach the last node at head
class Solution {
public:
    ListNode* insertAtFirst(ListNode* head, ListNode* node)
    {
        if(head==NULL) return node;
        
        
        node->next = head;
        head=node;
        
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* h=head;
        int cnt=1;
        if(head ==NULL or head->next==NULL) return head;
        while(h->next!=NULL)
        {
            h=h->next;
            cnt++;
        }
        h=head;
        
        k=k%cnt;
        
        while(k--)
        {
            ListNode* newNode;
            while(h->next->next!=NULL)
            {
                h=h->next;
            }
            newNode = h->next;
            h->next = NULL;
            head = insertAtFirst(head,newNode);
            h=head;
        }
        
        return head;
        
    }
};
