#include<iostream>
using namespace std;
//By using iteration
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

    //By iteration
    void reverse_linklist() {
        if (head == nullptr)
        {
            cout<<"List is empty";
        }
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current!=nullptr)
        {
            /* code */
            next = current -> next_node;
            current -> next_node = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    //By using Recursion
    Node* reverse_recursive(Node* current) {
    if (current == nullptr || current->next_node == nullptr)
        return current;

    Node* newHead = reverse_recursive(current->next_node);
    current->next_node->next_node = current;
    current->next_node = nullptr;

    return newHead;
}

    void reverse_linklist_recursion() {
    head = reverse_recursive(head);
    }

    void insert_start(int value){
        Node* newNode = new Node{value};
        if (head == nullptr)
        {
            head = newNode;
        }else{
            Node* current = head;
            newNode -> next_node = current;
            head = newNode;
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
    list.insert_start(10);
    list.insert_start(20);
    list.insert_start(30);
    list.insert_start(40);
    cout<<"Simple " << endl;
    list.print();
    //By iteration
    cout<<"Iteration "<<endl;
    list.reverse_linklist();
    list.print(); 

    //By using Recursion
    cout<< "Recursion " << endl;
    list.reverse_linklist_recursion();
    list.print();
}
