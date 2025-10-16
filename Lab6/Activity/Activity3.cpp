#include<iostream>
using namespace std;

class circularQueue
{
private:
    int size;
    int* arr;
    int front;
    int rear;
public:
    circularQueue(){
        size = 5;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    ~circularQueue(){
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int value){
        if (isFull())
        {
            cout<<"Array is full";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
    }

    void dequeue(){
        if (isEmpty())
        {
            cout<<"Queue is empty";
            return;
        }

        cout<<arr[front]<<"\n";

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display(){
        if (isEmpty())
        {
            cout<<"Queue is Empty";
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout<<"\n";
    }
};
int main(){
    circularQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    q.dequeue();
    q.dequeue();

    q.enqueue(6);
    q.enqueue(7);

    q.display();
}