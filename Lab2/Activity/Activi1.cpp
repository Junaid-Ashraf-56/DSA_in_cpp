#include<iostream>
using namespace std;

class Node
{
public:
    /* data */
    string data;
    Node* next_node;
    Node(const string& data): data(data),next_node(NULL){};
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert_end(string value){
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
    list.insert_end("Once");
    list.insert_end("upon");
    list.insert_end("a");
    list.insert_end("time");

    list.print(); 

    return 0;
}
