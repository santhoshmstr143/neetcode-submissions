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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        while(1)
        {
            int l = k;
            ListNode *kth = prev;
            for(int i=0;i<k && kth ;i++)
            {
                kth = kth->next;
            }
            if(kth==nullptr) break;
            ListNode *nxt = kth->next;
            ListNode *p = nxt;
            ListNode *c = prev->next;
            ListNode *n = nullptr;
            while(c!=nxt)
            {
                n = c->next;
                c->next = p;

                p = c;
                c = n;
            }
            ListNode *temp = prev->next;
            prev->next = kth;
            prev = temp;

        }
        return dummy->next;
    }
};
