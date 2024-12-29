struct Node {
    int data;
    Node* next;
};

class MyLinkedList {
private:
    Node* dummy;
public:
    MyLinkedList() {
        dummy = new Node();
        dummy->next = nullptr;
    }
    
    int get(int index) {
        if (index < 0) return -1;

        Node* curr = dummy;

        for (int i = 0 ; i < index + 1 && curr != nullptr ; i++) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            return -1;
        }
        return curr->data;
    }
    
    void addAtHead(int val) {
        Node* nodeToAdd = new Node();
        nodeToAdd->data = val;
        nodeToAdd->next = dummy->next;
        dummy->next = nodeToAdd;   
    }
    
    void addAtTail(int val) {
        Node* curr = dummy;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        Node* nodeToAdd = new Node();
        nodeToAdd->data = val;
        nodeToAdd->next = nullptr;
        curr->next = nodeToAdd;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0) {
            return;
        }

        Node* current = dummy;
        for (int i = 0 ; i < index && current != nullptr ; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            return;
        }

        Node* nodeToAdd = new Node();
        nodeToAdd->data = val;
        nodeToAdd->next = current->next;
        current->next = nodeToAdd;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0) return;

        Node* current = dummy;

        for (int i = 0; i < index && current->next != nullptr ; i++) {
            current = current->next;
        }

        if (current->next == nullptr) {
            return;
        }

        Node* nodeToDelete = current->next;
        current->next = current->next->next;
        delete nodeToDelete;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */