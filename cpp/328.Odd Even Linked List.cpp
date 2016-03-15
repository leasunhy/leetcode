// Date: 2016-3-15

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenhead = even;
        ListNode* cur = even->next;
        while (cur) {
            odd->next = cur;
            even->next = cur->next;
            odd = cur;
            if (cur->next == nullptr)
                break;
            even = cur->next;
            cur = even->next;
        }
        even->next = nullptr;
        odd->next = evenhead;
        return head;
    }
};
