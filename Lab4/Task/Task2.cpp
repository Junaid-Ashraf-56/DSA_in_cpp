class CNode {
public:
    int value;
    CNode* next;

    CNode(int val) {
        value = val;
        next = nullptr;
    }
};
class CircularLinkedList {
private:
    CNode* head = nullptr;

public:
    // Insert at end
    void insert(int val) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }

        CNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    int solveJosephus(int step) {
        if (!head || head->next == head || step <= 0) {
            return head ? head->value : -1;
        }

        CNode* current = head;
        CNode* prev = nullptr;

        while (current->next != current) {
            for (int i = 1; i < step; ++i) {
                prev = current;
                current = current->next;
            }

            prev->next = current->next;
            delete current;
            current = prev->next;
        }

        head = current;
        return current->value;
    }

    // Display list
    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        CNode* temp = head;
        do {
            cout << temp->value << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
};
int main() {
    CircularLinkedList clist;
    clist.insert(1);
    clist.insert(2);
    clist.insert(3);
    clist.insert(4);
    clist.insert(5);
    clist.insert(6);

    cout << "Original list:\n";
    clist.display();

    cout << "\nDeleting even nodes:\n";
    clist.deleteByParity(true);
    clist.display();
}
