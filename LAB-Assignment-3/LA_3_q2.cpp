#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    void push(char c) {
        arr[++top] = c;
    }

    char pop() {
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    Stack st;

    for (char c : s) {
        st.push(c);
    }

    cout << "Reversed string: ";

    while (!st.isEmpty()) {
        cout << st.pop();
    }

    return 0;
}
