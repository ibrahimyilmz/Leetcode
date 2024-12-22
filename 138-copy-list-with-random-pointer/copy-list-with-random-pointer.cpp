/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        unordered_map<Node*, Node*> hash;
        Node* first = head;
        Node* last = new Node(head->val);
        hash[first] = last;
        while (first->next != nullptr) {
            Node* temp = new Node(first->next->val);
            last->next = temp;
            first = first->next;
            last = last->next;
            hash[first] = last;
        }

        first = head;
        while (first != nullptr) {
            last = hash[first];
            last->random = hash[first->random];
            first = first->next;
        }
        return hash[head];
    }
};