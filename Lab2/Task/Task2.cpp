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

    void insert_end(int value){
        Node* newNode = new Node{value};
        if (head == nullptr)
        {
            head = newNode;
        }else{
            Node* current = head;
            while (current -> next_node!= nullptr)
            {
                /* code */
                current = current ->next_node ;
            }
            current -> next_node = newNode;

        }
    }

    static LinkedList merge(LinkedList l1 ,LinkedList l2){
        LinkedList merge;
        Node* current = l1.head;
        while (current != nullptr)
        {
            /* code */
            merge.insert_end(current->data);
            current = current->next_node;
        }
        
        Node* current1 = l2.head;
        while (current1!=nullptr)
        {
            /* code */
            merge.insert_end(current1->data);
            current1 = current1->next_node;
        }
        return merge;
        
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

    LinkedList list1;
    list1.insert_end(15);
    list1.insert_end(25);
    list1.insert_end(35);
    list1.insert_end(45);

    LinkedList merge = LinkedList ::merge(list,list1);
    merge.print();
}