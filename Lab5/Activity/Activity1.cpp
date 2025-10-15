#include<iostream>
using namespace std;
class stack
{
private:
    
    int size = 5;
    int arr[5];
    int top;

public:
    stack(){
        top = 0;
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
            cout<<"stack is full";
            return;
        }
        
        arr[top] = value;
        top++;
    }

    void peek(){
        if (isEmpty())
        {
            cout<<"Array is empty";
            return;
        }
        
        cout<<" Top element is "<<arr[top]<<"\n";
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
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    s.peek();

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

}