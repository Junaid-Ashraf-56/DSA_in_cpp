#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
private:
    string content;
    stack<string> undoStack;
    stack<string> redoStack;

    void limitUndoStack() {
        if (undoStack.size() > 100) {
            // Create a temporary stack to reverse and trim
            stack<string> temp;
            while (!undoStack.empty()) {
                temp.push(undoStack.top());
                undoStack.pop();
            }
            // Remove oldest (bottom-most) entry
            temp.pop();
            // Restore trimmed stack
            while (!temp.empty()) {
                undoStack.push(temp.top());
                temp.pop();
            }
        }
    }

public:
    void write(const string& text) {
        undoStack.push(content);
        content += text;
        while (!redoStack.empty()) redoStack.pop(); // Clear redo history
        limitUndoStack();
    }

    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo.\n";
            return;
        }
        redoStack.push(content);
        content = undoStack.top();        undoStack.pop();
    }

    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo.\n";
            return;
        }
        undoStack.push(content);
        content = redoStack.top();
        redoStack.pop();
    }

    void show() const {
        cout << "Current Content: \"" << content << "\"\n";
    }
};
int main() {
    TextEditor editor;
    editor.write("Hello");
    editor.write(" World");
    editor.show(); // Hello World

    editor.undo();
    editor.show(); // Hello

    editor.redo();
    editor.show(); // Hello World

    editor.undo();
    editor.undo();
    editor.show(); // (empty)

    editor.redo();
    editor.show(); // Hello
}
