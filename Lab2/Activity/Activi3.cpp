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

    void insert_start(string value){
        Node* newNode = new Node{value};
        if (head == nullptr)
        {
            head = newNode;
        }else{
            Node* current = head;
            newNode->next_node = head;
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
    list.insert_start("Once");
    list.insert_start("upon");
    list.insert_start("a");
    list.insert_start("time");

    list.print(); 

    return 0;
}
