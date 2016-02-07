// Date: 2016-2-7

#include <queue>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }
        std::queue<ListNode*> q;
        for (ListNode* cur = head; cur; cur = cur->next) {
            q.push(cur);
            if (q.size() > n + 1)
                q.pop();
        }
        if (q.size() == n + 1) {
            ListNode* prev = q.front();
            ListNode* deleted = prev->next;
            ListNode* next = deleted->next;
            prev->next = next;
            delete deleted;
        } else {
            // if so, the node to be deleted is head
            ListNode* old_head = head;
            head = old_head->next;
            delete old_head;
        }
        return head;
    }
};
