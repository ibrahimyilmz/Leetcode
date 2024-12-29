struct Node {
    int data;
    Node* next;
};

class MyLinkedList {
    Node* head;
public:
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        Node* curr = head;
        for (int i = 0 ; i < index && curr != nullptr ; i++) {
            curr = curr->next;
        }
        if (!curr) {
            return -1;
        }
        else {
            return curr->data;
        }
    }
    
    void addAtHead(int val) {
        if (!head) {
            head = new Node();
            head->data = val;
            head->next = nullptr;
        }
        else {
            Node* newHead = new Node();
            newHead->data = val;
            newHead->next = head;
            head = newHead;
        }
    }
    
    void addAtTail(int val) {
        if (head == nullptr) {
            head = new Node();
            head->next = nullptr;
            head->data = val;
            return;
        }

        Node* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
        }
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        tail->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0) return;

        if (index == 0) {
            Node* newHead = new Node();
            newHead->data = val;
            newHead->next = head;
            head = newHead;
            return;
        }

        Node* curr = head;
        for (int i = 0 ; i < index - 1 && curr != nullptr ; i++) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            return;
        }

        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = curr->next;
        curr->next = newNode;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0) return;

        if (!head) return;

        if (index == 0) {
            Node* temp = head->next;
            delete head;
            head = temp;
            return;
        }

        Node* tail = head;
        for (int i = 0 ; i < index - 1 && tail->next != nullptr ; i++) {
            tail = tail->next;
        }

        if (!tail->next) {
            return;
        }

        Node* nodeToDelete = tail->next;
        tail->next = tail->next->next;
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