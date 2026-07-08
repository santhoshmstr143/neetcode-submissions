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
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *p = nullptr , *c = slow->next , *n = nullptr;
        slow->next = nullptr;
        while(c)
        {
            n = c->next;
            c->next = p;

            p = c;
            c = n;
        }
        ListNode *first = head;
        ListNode *second = p;
        while(second)
        {
            ListNode *t1 = first->next;
            ListNode *t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};
