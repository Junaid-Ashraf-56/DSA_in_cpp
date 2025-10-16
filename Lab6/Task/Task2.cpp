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

    bool remove_first() {
        if (head == nullptr) {
            cout << "Queue is empty\n";
            return false;
        }
        Node* temp = head;
        cout << "Dequeued: " << temp->data << "\n";
        head = head->next_node;
        delete temp;
        return true;
    }

    void print() {
        if (head == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        Node* current = head;
        cout << "Queue elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next_node;
        }
        cout << "\n";
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

class queue
{
private:
    LinkedList list;
public:

   void enqueue(int value){
    list.insert_end(value);
   }

   void dequeue(){
    list.remove_first();
   }
   void display(){
    list.print();
   }
};

int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

}