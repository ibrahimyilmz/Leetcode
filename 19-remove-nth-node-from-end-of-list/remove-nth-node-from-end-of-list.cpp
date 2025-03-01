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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* first = &dummy;
        ListNode* second = &dummy;

        for (int i = 1 ; i <= n + 1; i++) {
            first = first->next;
        }

        while (first != nullptr) {
            second = second->next;
            first = first->next;
        }

        second->next = second->next->next;
        return dummy.next;
    }
};