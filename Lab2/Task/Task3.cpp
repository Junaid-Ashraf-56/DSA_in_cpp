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

    int search(int value){
        if (head == nullptr)
        {
            /* code */
            cout<<"List is empty";
        }
        int sum = 0;
        Node* current = head;
        while (current!=nullptr)
        {
            /* code */
            if (current->data == value)
            {
                /* code */
                sum++;
            }   
            current = current -> next_node;
        }
        cout << "Value found " << sum << " times." << endl;
        return sum;
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
    list.insert_start(10);
    list.insert_start(10);
    list.insert_start(20);
    list.insert_start(30);
    list.insert_start(40);
    cout<<"Simple " << endl;
    list.print();

    list.search(10);
}
