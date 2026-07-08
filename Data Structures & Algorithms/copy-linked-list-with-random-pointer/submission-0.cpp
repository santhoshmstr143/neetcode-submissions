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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        Node *lol = head;
        while(lol)
        {
            Node *temp = new Node(lol->val);
            temp->next = lol->next;
            lol->next = temp;
            lol = temp->next;
        }
        lol = head;
        while(lol)
        {
            if(lol->random)
                lol->next->random = lol->random->next;

            lol = lol->next->next;
        }
        Node *dummy = new Node(0);
        Node *ans = dummy;
        lol = head;
        while(lol)
        {
            ans->next = lol->next;
            ans = ans->next;
            lol->next = lol->next->next;
            lol=lol->next;
        }
        return dummy->next;
        
    }
};
