#include<iostream>
using namespace std;
class Node
{
public:
    /* data */
    int data;
    Node* next_node;
    Node(int value) : data(value), next_node(nullptr) {}
};
class LinkedList
{
private:
    /* data */
    Node* head;
public:
    LinkedList(/* args */): head(nullptr) {};
    ~LinkedList(){
        Node* current = head;
        while (current!=nullptr)
        {
            /* code */
            Node* next = current ->next_node;
            delete current;
            current = next;
        }
        
    }

    void insertStart(int value){
        Node* newNode = new Node{value};
        if (head==nullptr)
        {
            /* code */
            head = newNode;
        }else{
            newNode->next_node = head;
            head = newNode;
        }
        
    }

    void insertEnd(int value){
        Node* newNode = new Node{value};
        if (head == nullptr)
        {
            /* code */
            head = newNode;
        }else{
            Node* current = head;
            while (current ->next_node!= nullptr)
            {
                /* code */
                current = current ->next_node;
            }
            current->next_node = newNode;
        }
    }

    void insertAt(int value, int insertvalue){
        Node* newNode = new Node{value};
        Node* current = head;
        while (current!=nullptr && current->data!=insertvalue)
        {
            /* code */
            current = current->next_node;
        }
        if (current==nullptr)
        {
            /* code */
            cout<<"Value not found";
            return;
        }
        
        newNode->next_node=current->next_node;
        current->next_node=newNode;
    }

    void deleteRoll(int value){
        if (head == nullptr)return ;
        
        if (head->data==value)
        {
            /* code */
            Node* temp = head;
            head = head -> next_node;
            delete temp;
            return;
        }
        
        Node* current = head;
        while (current->next_node!=nullptr&&current->next_node->data!=value)
        {
            /* code */
            current = current->next_node;
        }

        if (current==nullptr)
        {
            /* code */
            cout<<"Value not found ";
            return;
        }
        Node* temp = current->next_node;
        current->next_node = temp->next_node;
        delete temp;
        
    }

    void search(int value){
        Node* current = head;
        while (current!=nullptr && current->data!=value)
        {
            /* code */
            current = current->next_node;
        }
        if (current->next_node == nullptr)
        {
            /* code */
            cout<<"Not found";
            return;
        }else{
            cout<<"Roll number is"<<current->data;
        }
    }

    void forwardOrder(){
        Node* current = head;
        while (current!=nullptr)
        {
            /* code */
            cout<<current->data<<" -> ";
            current = current->next_node;
        }
        cout<<"end";
    }
};
int main(){
    LinkedList list;
    list.insertStart(03);
    list.insertStart(02);
    list.insertStart(01);

    list.forwardOrder();

    cout<<"\n";
    list.deleteRoll(02);

    list.forwardOrder();
    cout<<"\n";
    return 0;
}