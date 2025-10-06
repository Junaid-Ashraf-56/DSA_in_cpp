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

    //insert at last
    void insertLast(int value){
        if (head==nullptr)
        {
            /* code */
            insertFirst(value);
        }
        Node* newNode = new Node(value);
        newNode->prev = tail;
        newNode->next = nullptr;

        tail->next = newNode;
        tail = newNode;
    }

    //delete specific number 
    void deleteSpecific(int value){
        if (head==nullptr)
        {
            cout<<"list is empty";
        }
        Node* current = head;

        while (current != nullptr) {
            if (current->value == value) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }

                delete current;
                cout << "Deleted successfully" << endl;
                return;
            }
            current = current->next;
        }

    cout << "Value not found" << endl;
    }

    //display all values
    void display(){
        if (head==nullptr)
        {
            cout<<"Linked list is empty";
            /* code */
        }
        Node* current = head;
        // cout<<"head "<<"\n";
        // while (current!=nullptr)
        // {
        //     cout<<"Current value "<<current->value<<" "<<"\n";
        //     cout<<"Current address "<<current <<"\n";
        //     cout<<"Previous address "<<current->prev<<" "<<"\n";
        //     cout<<"Next address "<<current->next<<" "<<"\n";
        //     current = current->next;
        //     cout<<"\n";
        // }
        // cout<<"null" <<"\n";
        
        // current = head;

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
    list.insertFirst(5);
    list.insertFirst(4);
    list.insertFirst(3);
    list.insertLast(6);
    list.insertLast(8);
    list.insertBefore(2,3);
    list.insertBefore(7,8);
    list.insertAfter(9,8);
    list.insertFirst(1);
    list.display();

    list.deleteSpecific(5);
    // list.search(5);
    // list.search(10);

    return 0;
}

