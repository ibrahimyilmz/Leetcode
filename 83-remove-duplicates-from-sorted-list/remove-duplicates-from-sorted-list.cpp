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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        if (!head->next) {
            return head;
        }

        ListNode* tail = head;
        ListNode* current = head->next;
        while (current) {
            if (current->val == tail->val) {
                tail->next = current->next;
                delete current;
                current = tail->next;
            }
            else {
                tail = current;
                current = current->next;
            }
        } 
        return head;
    }
};