class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL || left == right)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy;
        for(int i = 1; i < left; i++)
            prev = prev->next;

        ListNode *curr = prev->next;
        ListNode *next = NULL;
        ListNode *p = NULL;

        for(int i = left; i <= right; i++)
        {
            next = curr->next;
            curr->next = p;
            p = curr;
            curr = next;
        }

        ListNode *tail = prev->next;

        prev->next = p;
        tail->next = curr;

        return dummy->next;
    }
};