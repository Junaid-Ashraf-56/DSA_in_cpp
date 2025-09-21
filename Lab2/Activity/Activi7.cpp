#include<iostream>
using namespace std;

class Node
{
public:
    /* data */
    int data;
    Node* next_node;
    Node(const int data): data(data),next_node(NULL){};
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void delete_spec(int key) {
        if (head == nullptr) {
        cout << "Empty Linked List" << endl;
        return;
        }
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != key) {
        prev = current;
        current = current->next_node;
        }

        if (current == nullptr) {
        cout << "Value " << key << " not found in the list." << endl;
        return;
        }

        if (prev == nullptr) {
            head = current->next_node;
        } else {
            prev->next_node = current->next_node;
        }

        delete current;
    }


    void insert_end(int value){
        Node* newNode = new Node{value};
        if (head == nullptr)
        {
            head = newNode;
        }else{
            Node* current = head;
            while (current-> next_node!=nullptr)
            {
               current = current -> next_node;

            }
            current -> next_node = newNode;
        }
    }
    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next_node;
        }
        cout << endl;
    }

      ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next_node;
            delete temp;
        }
    }
};
int main(){
 LinkedList list;
    list.insert_end(10);
    list.insert_end(20);
    list.insert_end(30);
    list.insert_end(40);

    list.delete_spec(20);

    list.print(); 

    return 0;
}
