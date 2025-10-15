// Using the stack check that the given expression has balanced paranthesis or not.
#include<iostream>
#include<cstring>
using namespace std;
class stack
{
private:
    int size;
    char* arr;
    int top;

public:
    stack() {
        size = 5;
        arr = new char[size];
        top = 0;
    }

    ~stack() {
        delete[] arr;
    }

    void resize() {
        int newSize = size * 2;
        char* temp = new char[newSize];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        size = newSize;
    }
    char pop(){
        if (isEmpty())
        {
            cout<<"Stack is empty";
            return'\0';
        }
        return arr[--top];
    }

    void push(char value){
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

class checkOrder
{
public:
    bool isMatching(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '[' && close == ']') ||
               (open == '{' && close == '}');
    }
    void check(string expr) {
        stack s;
        for (char ch : expr) {
            if (ch == '(' || ch == '[' || ch == '{') {
                s.push(ch);
            } else if (ch == ')' || ch == ']' || ch == '}') {
                if (s.isEmpty()) {
                    cout << "Not a valid parenthesis\n";
                    return;
                }
                char topChar = s.pop();
                if (!isMatching(topChar, ch)) {
                    cout << "Not a valid parenthesis\n";
                    return;
                }
            }
        }

        if (s.isEmpty()) {
            cout << "Valid parenthesis\n";
        } else {
            cout << "Not a valid parenthesis\n";
        }
    }
};


int main(){
    string para = "{[()]}";
    checkOrder c1;
    c1.check(para);
}