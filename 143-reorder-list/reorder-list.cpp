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
        ListNode* walker = head;
        ListNode* runner = head;

        while (runner->next != nullptr && runner->next->next != nullptr) {
            walker = walker->next;
            runner = runner->next->next;
        }

        ListNode* current = walker->next;
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current-> next = pre;
            pre = current;
            current = next;
        }

        walker->next = nullptr;
        // Merge the two halves
        ListNode* first = head;
        ListNode* second = pre;
        while (second != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};