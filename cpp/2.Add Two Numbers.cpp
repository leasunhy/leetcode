// Date: 2016-2-5

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* cur;
        ListNode* root = cur = new ListNode(-1);
        while (l1 != nullptr || l2 != nullptr) {
            int v1 = getValAndAdvance(l1);
            int v2 = getValAndAdvance(l2);
            int sum = v1 + v2 + carry;
            carry = (sum >= 10 ? 1 : 0);
            int digit = (carry == 1 ? sum - 10 : sum);
            cur -> next = new ListNode(digit);
            cur = cur->next;
        }
        if (carry == 1)
            cur->next = new ListNode(1);
        ListNode* res = root->next;
        delete root;
        return res;
    }
private:
    inline int getValAndAdvance(ListNode*& node) {
        if (node == nullptr)
            return 0;
        int val = node->val;
        node = node->next;
        return val;
    }
};
