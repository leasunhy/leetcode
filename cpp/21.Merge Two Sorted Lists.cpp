// Date: 2016-07-26

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (l1 || l2) {
            if (l1 && l2) {
                if (l1->val < l2->val) {
                    cur->next = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    cur->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
            } else if (l1) {
                cur->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                cur->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            cur = cur->next;
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};

