#include<iostream>
using namespace std;

class Node
{
public:
    Node* next;
    Node* prev;
    int value;

    Node(int value){
        this->value = value;
    }
    Node(Node* next,Node* prev,int value){
        this->next = next;
        this->prev=prev;
        this->value=value;
    }
};
class dll
{
private:
    Node* head = nullptr;
    Node* tail = nullptr;
public:

    //insert at start
    void insertFirst(int value){
        Node* newNode = new Node(value);
        
        newNode ->next=head;
        newNode ->prev=nullptr;
        
        if (head!=nullptr)
        {
            head->prev=newNode;
        }else{
            tail = newNode;
        }
        
        head = newNode;
    }

    //Swap 2 nodes
    void swap(int val1,int val2){
        if (val1==val2)
        {
            cout<<"No need to swap these values";
            return;
        }
        
        Node* node1 = nullptr;
        Node* node2 = nullptr;

        while (head!=nullptr)
        {
            Node* current = head;
            if (current->value==val1)
            {
                node1 = current;
            }
            if (current->value==val2)
            {
                node2 = current;
            }
            current = current->next;
        }

        //values are not present
        if(node1==nullptr || node2==nullptr){
            cout<<"one or both are not in the list";
            return;
        }

        //Case 1: If node1 is before node2
        if (node1->next==node2)
        {
            if (node1->prev)node1->prev->next=node2;
            if (node2->next)node2->next->prev=node1;

            node1->next = node2->next;
            node2->prev = node1->prev;

            node2->next=node1;
            node1->prev=node2;
        }else if(node2->next==node1)
        {
            if (node2->prev)node2->prev->next=node1;
            if (node1->next)node1->next->prev=node2;

            node2->next=node1->next;
            node1->prev=node2->prev;

            node1->next=node2;
            node2->prev=node1;
        }else
        {
            Node* tempPrev = node1->prev;
            Node* tempNext = node1->next;

            if (node1->prev) node1->prev->next = node2;
            if (node1->next) node1->next->prev = node2;

            if (node2->prev) node2->prev->next = node1;
            if (node2->next) node2->next->prev = node1;

            node1->prev = node2->prev;
            node1->next = node2->next;

            node2->prev = tempPrev;
            node2->next = tempNext;
        }
        
        if (head == node1) head = node2;
        else if (head == node2) head = node1;

        if (tail == node1) tail = node2;
        else if (tail == node2) tail = node1;

        cout << "Nodes swapped successfully.\n";

    }
       //display all values
    void display(){
        if (head==nullptr)
        {
            cout<<"Linked list is empty";
            /* code */
        }
        Node* current = head;
        cout<<"head "<<" -> ";
        while (current!=nullptr)
        {
           cout<<current->value<<" -> ";
           current=current->next;
        }
        cout<<"null"<<"\n";
    }

    //Destructor
    ~dll() {
        Node* current = head;
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
    dll list;
    list.insertFirst(4);
    list.insertFirst(3);
    list.insertFirst(2);
    list.insertFirst(1);

    list.display();
}