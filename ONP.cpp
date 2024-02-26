#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cctype>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    } else {
        return 0;
    }
}

string to_rpn(const string& expr) {
    stack<char> op_stack;
    queue<char> output_queue;
    for (int i = 0; i < expr.length(); i++) {
        char token = expr[i];
        if (isalpha(token)) {
            output_queue.push(token);
        } else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '^') {
            while (!op_stack.empty() && op_stack.top() != '(' && precedence(token) <= precedence(op_stack.top())) {
                output_queue.push(op_stack.top());
                op_stack.pop();
            }
            op_stack.push(token);
        } else if (token == '(') {
            op_stack.push(token);
        } else if (token == ')') {
            while (!op_stack.empty() && op_stack.top() != '(') {
                output_queue.push(op_stack.top());
                op_stack.pop();
            }
            if (!op_stack.empty()) {
                op_stack.pop();
            }
        }
    }
    while (!op_stack.empty()) {
        output_queue.push(op_stack.top());
        op_stack.pop();
    }
    string rpn_expr;
    while (!output_queue.empty()) {
        rpn_expr += output_queue.front();
        output_queue.pop();
    }
    return rpn_expr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string expr;
        getline(cin, expr);
        cout << to_rpn(expr) << endl;
    }
    return 0;
}

