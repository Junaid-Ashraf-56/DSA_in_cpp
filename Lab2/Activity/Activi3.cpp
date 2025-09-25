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

    void access_value(int value){
        Node* current = head;
        int key = value;

        while (current != nullptr && current -> data != key)
        {
            /* code */
            current = current -> next_node;
        }

        if (current != nullptr)
        {
            cout<< "found  " << current-> data << endl;
        }else{
            cout<<"Not found";
        }
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

    list.access_value(20);

    // list.print(); 

    return 0;
}
