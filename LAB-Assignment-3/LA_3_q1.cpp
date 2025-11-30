#include <iostream>
using namespace std;
#define MAX 5   
class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack is Full\n";
        } else {
            arr[++top] = x;
            cout << "Pushed " << x << endl;
        }
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
        } else {
            cout << "Popped " << arr[top--] << endl;
        }
    }
    void peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
        } else {
            cout << "Top Element: " << arr[top] << endl;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    Stack st;
    int choice, x;
    while (true) {
        cout << "\n1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                st.push(x);
                break;

            case 2:
                st.pop();
                break;

            case 3:
                cout << (st.isEmpty() ? "Stack is Empty\n" : "Stack is Not Empty\n");
                break;

            case 4:
                cout << (st.isFull() ? "Stack is Full\n" : "Stack is Not Full\n");
                break;

            case 5:
                st.display();
                break;

            case 6:
                st.peek();
                break;

            case 7:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
