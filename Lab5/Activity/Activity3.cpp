#include<iostream>
#include<cstring>

using namespace std;
class stack
{
private:
    
    int size = 50;
    char arr[50];
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

    void push(char value){
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
        
        cout<<" Top element is "<<arr[top-1]<<"\n";
    }
    bool isEmpty() {
        return top == 0;
    }

    bool isFull() {
        return top == size;
    }
};
int main()
{
    stack s1;
    char str[]="I Love Programming";

    int len = strlen(str);

    for(int i=0; i<len; i++)
        s1.push(str[i]);

    for(int i=0; i<len; i++)
        s1.pop();
}