#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

 string prefixToPostfix(const  string& prefix) {
     stack< string> stack;
    int length = prefix.length();

    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
             string operand1 = stack.top();
            stack.pop();
             string operand2 = stack.top();
            stack.pop();
             string postfixExpression = operand1 + operand2 + prefix[i];
            stack.push(postfixExpression);
        } else {
            stack.push( string(1, prefix[i]));
        }
    }

    return stack.top();
}

int main() {
     string prefixExpression = "*-A/BC-/AKL";

     string postfixExpression = prefixToPostfix(prefixExpression);
     cout << "Postfix expression: " << postfixExpression <<  endl;

    return 0;
}
