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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list1 = l1;
        ListNode* list2 = l2;
        ListNode dummy;
        ListNode* result = &dummy;
        int carry = 0;
        while (list1 != nullptr || list2 != nullptr) {
            int val1 = 0;
            int val2 = 0;
            if (list1 != nullptr) {
                val1 = list1->val;
            }
            if (list2 != nullptr) {
                val2 = list2->val;
            }
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            result->next = new ListNode(sum);
            result = result->next;
            if (list1 != nullptr) {
                list1 = list1->next;
            }
            if (list2 != nullptr) {
                list2 = list2->next;
            }
        }
        if (carry != 0) {
            result->next = new ListNode(carry);
        }
        return dummy.next;
    }
};