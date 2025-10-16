#include<iostream>
using namespace std;

class queue
{
private:
    int size;
    int* arr;
    int front;
    int rear;
public:
    queue(){
        size = 5;
        arr = new int[size];
        front = 0;
        rear = -1;
    }
    ~queue(){
        delete[] arr;
    }

    bool isEmpty(){
        return rear < front;
    }

    bool isFull(){
        return rear==size-1;
    }

    void insert_end(int value){
        if (isFull())
        {
            cout<<"Array is full";
            return;
        }
        arr[++rear] = value;
    }

    void insert_at_beg(int value){
        if (isFull())
        {
            cout<<"Array is full";
            return;
        }
        for (int i = rear+1; i >=front; i--)
        {
            arr[i] = arr[i-1] ;
        }
        arr[front] = value;
        rear++;
    }

    void delete_fr_beg(){
        if (isEmpty())
        {
            cout<<"Queue is empty";
            return;
        }
        for (int i = 1; i <= rear; i++)
        {
            arr[i-1] = arr[i] ;
        }
        rear--;
    }

    void delete_fr_rear(){
        if (isEmpty())
        {
            cout<<"Queue is empty";
            return;
        }
        rear--;
    }

    void display(){
        if (isEmpty())
        {
            cout<<"Queue is Empty";
            return;
        }
        for (int i = 0; i <= rear; i++)
        {
            cout<<arr[i]<<"\n";
        }
    }
};
int main() {
    queue q;
    q.insert_end(1);
    q.insert_end(2);
    q.insert_end(3);
    q.insert_end(4);
    q.insert_end(5);

    q.display();

    cout << "After deleting from front:\n";
    q.delete_fr_beg();
    q.display();

    cout << "After deleting from rear:\n";
    q.delete_fr_rear();
    q.display();

    cout << "After inserting at beginning:\n";
    q.insert_at_beg(99);
    q.display();
}