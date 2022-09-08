// LINK : https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//Using hashmap to store nodes
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL) return head;

        Node* head2 = new Node(head->val);
        Node* h = head, *h2 = head2;
        unordered_map<Node*,Node*> mp;

        mp[h] = head2;
        if(h->next==NULL)
        {
            if(h->random == NULL) return head2;
            else
            {
                head2->random=head2;
            }
            return head2;
        }
        
        h=h->next;
        while(h!=NULL)
        {
            Node* temp = new Node(h->val);
            head2->next = temp;
            head2=temp;
            mp[h]=temp;
            h=h->next;
        }
        
        h=head, head2 = h2;
        while(h!=NULL and head2!=NULL)
        {
            Node* rand = h->random;
            head2->random = mp[rand];
            h=h->next;
            head2=head2->next;
        }

       
        return h2;
    }
};


//Using modified LL
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL) return head;
        
        Node* h = head, *copyhead = h;
        // First round: make copy of each node,
        // and link them together side-by-side in a single list.
        while(h!=NULL)
        {
            Node* newnode = new Node(h->val);
            Node* nextNode = h->next;
            h->next = newnode;
            newnode->next = nextNode;
            h=nextNode;
        }
        
        Node* dummy = new Node(-1), *front;
        h = head;
        
         // Second round: assign random pointers for the copy nodes.
        while(h!=NULL)
        {
            if(h->random!=  NULL)
                h->next->random = h->random->next;
            
            h=h->next->next;
        }
        
        h=head, copyhead = dummy;
        // Third round: restore the original list, and extract the copy list.
        while(h!=NULL)
        {
            front = h->next->next;
            copyhead->next = h->next;
            h->next = front;
            copyhead=copyhead->next;
            h=front;
            
        }
        
        return dummy->next;
        
    }
};
