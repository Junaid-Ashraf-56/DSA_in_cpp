#include<iostream>
using namespace std;
class LinkedList
{
private:
    /* data */
    string data;
    LinkedList* next_node;

public:
    LinkedList(const string& data): data(data),next_node(NULL){};
    LinkedList(string data,LinkedList* next_node){
        this->data=data;
        this->next_node=next_node;
    }
    void setNext(LinkedList* next){
        next_node = next;
    }
    LinkedList* getNext(){
        return next_node;
    }

    void print() {
        LinkedList* current = this;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->getNext();
        }
        cout << endl;
    }
};
int main(){

    LinkedList* head = NULL;
    LinkedList* node1 = new LinkedList{"Once"};
    LinkedList* node2 = new LinkedList{"upon"};
    LinkedList* node3 = new LinkedList{"a"};
    LinkedList* node4 = new LinkedList{"time"};

    head = node1;
    node1 -> setNext(node2);
    node2 -> setNext(node3);
    node3 -> setNext(node4);
    node4 -> setNext(NULL);

    head -> print();

    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
