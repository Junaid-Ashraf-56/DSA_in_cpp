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

    void enqueue(int value){
        if (isFull())
        {
            cout<<"Array is full";
            return;
        }
        arr[++rear] = value;
    }

    void dequeue(){
        if (isEmpty())
        {
            cout<<"Queue is empty";
            return;
        }

        cout<<arr[front]<<"\n";
        for (int i = 1; i <= rear; i++)
        {
            arr[i-1] = arr[i] ;
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
int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

}