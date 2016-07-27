// Date: 2016-07-27

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;
    ListNode* mid = head, * tail = head;
    while (mid->next && tail->next && tail->next->next)
        mid = mid-> next, tail = tail->next->next;
    if (tail->next)
        tail = tail->next;  // now it's tail :-)
    ListNode* last = NULL, * cur = mid->next;
    while (cur) {
        ListNode* next = cur->next;
        cur->next = last;
        last = cur;
        cur = next;
    }
    while (last) {
        printf("%d : %d\n", head->val, last->val);
        if (head->val != last->val)
            return false;
        head = head->next;
        last = last->next;
    }
    return true;
}


