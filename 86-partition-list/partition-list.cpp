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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = nullptr;
        ListNode* bigHead = nullptr;
        ListNode* lessTail = nullptr;
        ListNode* bigTail = nullptr;
        ListNode* curr = head;
        while (curr) {
            if (curr->val >= x) {
                if (!bigHead) {
                    bigHead = curr;
                    bigTail = curr;
                }
                else {
                    bigTail->next = curr;
                    bigTail = curr;
                }
            }
            else {
                if (!lessTail) {
                    lessHead = curr;
                    lessTail = curr;
                }
                else {
                    lessTail->next = curr;
                    lessTail = curr;
                }
            }
            curr = curr->next;
        }

        if (lessHead == nullptr) {
            return bigHead;
        }

        lessTail->next = bigHead;
        
        if (bigTail != nullptr) {
            bigTail->next = nullptr;
        }
        
        return lessHead;
    }
};