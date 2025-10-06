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

   void deleteEvenPositions() {
    if (!head || !head->next) return;

    Node* current = head;
    Node* prev = nullptr;
    int position = 1;

    while (current != nullptr) {
        if (position % 2 == 0) {
            Node* toDelete = current;
            prev->next = current->next;
            if (current->next) {
                current->next->prev = prev;
            } else {
                tail = prev; // Update tail if last node is deleted
            }
            current = current->next;
            delete toDelete;
        } else {
            prev = current;
            current = current->next;
        }
        position++;
    }
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
