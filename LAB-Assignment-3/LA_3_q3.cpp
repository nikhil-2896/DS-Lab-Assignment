#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string exp) {
    stack<char> st;

    for (char c : exp) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {

            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
        }
    }
    return st.empty();
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;

    if (isBalanced(exp))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
