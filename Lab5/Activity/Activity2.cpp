#include<iostream>
using namespace std;
class stack
{
private:
   int size;
    int* arr;
    int top;

public:
    stack() {
        size = 5;
        arr = new int[size];
        top = 0;
    }

    ~stack() {
        delete[] arr;
    }

    void resize() {
        int newSize = size * 2;
        int* temp = new int[newSize];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        size = newSize;
    }
    void pop(){
        if (isEmpty())
        {
            cout<<"Stack is empty";
            return;
        }
        top--;
        cout<<arr[top];
    }

    void push(int value){
        if (isFull())
        {
             resize();
        }
        
        arr[top] = value;
        top++;
    }

    void peek(){
        if (isEmpty())
        {
            cout<<"Array is empty"<<"\n";
            return;
        }
        
        cout<<" Top element is "<<arr[top-1]<<"\n";
    }


    bool isEmpty() {
        return top == 0;
    }

    bool isFull() {
        return top == size;
    }
};
int main(){
    stack s;
    s.peek();
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    s.pop();
    cout<<"\n";
    s.pop();
    cout<<"\n";
    s.pop();
    cout<<"\n";
    s.pop();
    cout<<"\n";
    s.pop();
    cout<<"\n";

    s.pop();
    cout<<"\n";
    s.pop();
    cout<<"\n";
    s.pop();
    cout<<"\n";
    s.pop();
    cout<<"\n";
    s.peek();
    cout<<"\n";

}