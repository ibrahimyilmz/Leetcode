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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }
        ListNode* current = head;
        int size = 0;
        while (current != nullptr) {
            current = current->next;
            size++;
        }
        k = k % size;
        if (k == 0) {
            return head;
        }
        ListNode* walker = head;
        ListNode* runner = head;
        for (int i = 0 ; i < k ; i++) {
            runner = runner->next;
        }

        while (runner->next != nullptr) {
            walker = walker->next;
            runner = runner->next;
        }

        ListNode* newHead = walker->next;
        walker->next = nullptr;
        runner->next = head;
        return newHead;
    }
};