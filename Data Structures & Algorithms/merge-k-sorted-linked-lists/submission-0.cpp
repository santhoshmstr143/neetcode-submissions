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
    ListNode* merge(ListNode *a,ListNode *b)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;
        while(a && b)
        {
            if(a->val < b->val)
            {
                temp->next = a;
                a = a->next;
            }
            else
            {
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }
        if(a)
        {
            temp->next = a;
        }
        else
        {
            temp->next = b;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() ==0) return nullptr;

        while(lists.size()>1)
        {
            vector<ListNode*> temp;
            for(int i=0;i<lists.size();i+=2)
            {
                if(i+1<lists.size())
                {
                    temp.push_back(merge(lists[i],lists[i+1]));
                }
                else
                {
                    temp.push_back(lists[i]);
                }
            }
            lists = temp;
        }
        return lists[0];
        
    }
};
