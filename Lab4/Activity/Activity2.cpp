#include<iostream>
using namespace std;
class Node
{
public:
    Node* next;
    int value;

    Node(int value){
        this->value=value;
    }
    Node(int value,Node* next){
        this->value=value;
        this->next = next;
    }
};
class cll
{
private:
    Node* head;
    Node* tail;
public:

    cll(){
        head = nullptr;
        tail = nullptr;
    }
    void insertFirst(int value){
        Node* newNode = new Node(value);
        if (head==nullptr)
        {
            head = tail = newNode;
            newNode->next = newNode;
        }else{
            newNode->next=head;
            tail->next = newNode;
            head = newNode;
        }
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node* current = head;
        do {
            cout << "value " << current->value << "\n";
            cout << "current address " << current << "\n";
            cout << "next address " << current->next << "\n";
            current = current->next;
        } while (current != head);
    }


    ~cll() {
        if (!head) return;

        Node* current = head;

        // Break the circular link first
        tail->next = nullptr;

        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
        tail = nullptr;
        cout << "All nodes deleted. Destructor called." << endl;
    }

};
int main(){
    cll list;
    list.insertFirst(3);
    list.insertFirst(2);
    list.insertFirst(1);
    list.insertLast(4);
    list.insertLast(6);
    list.insertAfter(5,4);
    list.insertBefore(7,1);
    list.deleteSpecific(7);
    list.deleteSpecific(3);
    list.display();

}