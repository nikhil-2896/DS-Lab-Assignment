#include <iostream>
#include <queue>
using namespace std;

class Stack1Q {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 1; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack1Q s;
    s.push(5);
    s.push(15);
    s.push(25);

    cout << s.top() << endl; 
    s.pop();
    cout << s.top() << endl; 

    return 0;
}
