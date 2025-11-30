#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

string infixToPostfix(string s) {
    stack<char> st;
    string postfix = "";

    for(char c : s) {

        if (isalnum(c)) {          
            postfix += c;
        }

        else if (c == '(') {       
            st.push(c);
        }

        else if (c == ')') {       
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();  
        }

        else if (isOperator(c)) {  
            while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string exp;
    cout << "Enter infix expression: ";
    cin >> exp;

    cout << "Postfix: " << infixToPostfix(exp);
}
