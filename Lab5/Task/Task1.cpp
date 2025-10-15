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

    char peek(){
        if (isEmpty())
        {
           return'\0';
        }
        
        return arr[top-1];
    }


    bool isEmpty() {
        return top == 0;
    }

    bool isFull() {
        return top == size;
    }
};

class checkBalance
{
public:
    int getPriority(char ch) {
        if (ch == '(') return 1;
        if (ch == '{') return 2;
        if (ch == '[') return 3;
        return 0;
    }

    bool isMatching(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '[' && close == ']') ||
               (open == '{' && close == '}');
    }

    bool isBalanced(const string& expr) {
        stack s;
        for (char ch : expr) {
            if (ch == '(' || ch == '[' || ch == '{') {
                if (!s.isEmpty()) {
                    char topChar = s.peek();
                    if (getPriority(ch) > getPriority(topChar)) {
                        return false;
                    }
                }
                s.push(ch);
            }
            else if (ch == ')' || ch == ']' || ch == '}') {
                char topChar = s.pop();
                if (!isMatching(topChar, ch)) {
                    return false;
                }
            }
        }
        return s.isEmpty();
    }
};


int main(){
    string para = "[()]";
    checkBalance c1;
    if (c1.isBalanced(para)) {
        cout << "Balanced\n";
    } else {
        cout << "Not Balanced\n";
    }
}