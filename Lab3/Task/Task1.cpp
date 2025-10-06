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

    //Reverse linked list
    void reverseLinkedList(dll head){
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }

        return head;
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