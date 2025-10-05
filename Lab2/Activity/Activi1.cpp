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

    void before_specific(int value,int before_specific){
        Node* newNode = new Node{value};
        if (head==nullptr)
        {
            /* code */
            cout<<"Specific number not present";
            return;
        }
        Node* current = head;
        while (current->next_node!=nullptr&&current->next_node->data!=before_specific)
        {
            /* code */
            current = current->next_node;
        }
        if (current!=nullptr)
        {
            /* code */
            newNode->next_node=current->next_node;
            current->next_node = newNode;
        }else{
            cout<<"Number not present ";
        }
    }

    void after_specific(int value,int after_specific){
        Node* newNode = new Node{value};
        if (head==nullptr)
        {
            /* code */
            cout<<"Specific number not present";
            return;
        }
        Node* current = head;
        while (current->next_node!=nullptr&&current->data!=after_specific)
        {
            /* code */
            current = current->next_node;
        }
        if (current!=nullptr)
        {
            /* code */
            newNode->next_node=current->next_node;
            current->next_node = newNode;
        }else{
            cout<<"Number not present ";
        }
    }

    void print() {
        Node* current = head;
        cout<<"Head" <<" -> "<<head <<"\n";
        cout<<"----\n";
        while (current != nullptr) {
            cout <<  "Current data  "<<current->data << " \n "<<"Current Address" <<current<<"\n";
            cout<<"Next Address"<<current->next_node<<"\n";
            cout<<"----\n";
            current = current->next_node;
        }
        cout<<"NULL";
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
    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);

    // list.print(); 

    list.before_specific(5,2);
    // list.print();

    list.after_specific(6,4);
    list.print();

    return 0;
}
