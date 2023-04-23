#include <iostream>
#include "Stack.cpp"
#include <string>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to check if a character is an operand
bool isOperand(char ch) {
    return (isalpha(ch) || isdigit(ch));
}

// Function to get the precedence of an operator
int getPrecedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix) {
    string postfix = "";
    Stack<char> S1;
    for (int i = 0; i < infix.length(); ++i) {
        char ch = infix[i];
        if (isOperand(ch)) {
            postfix += ch;
        } else if (isOperator(ch)) {
            while (!S1. isEmpty() && getPrecedence(S1.Top()) >= getPrecedence(ch)) {
                postfix += S1.Top();
                S1.pop();
            }
            S1.push(ch);
        } else if (ch == '(') {
            S1.push(ch);
        } else if (ch == ')') {
            while (!S1. isEmpty() && S1.Top() != '(') {
                postfix += S1.Top();
                S1.pop();
            }
            S1.pop();
        }
    }
    while (!S1. isEmpty()) {
        postfix += S1.Top();
        S1.pop();
    }
    return postfix;
}

int main() {
    
    string infix1 = "X^Y / (5*Z) + 2";
    string infix2 = "A + B * C + D";
    string infix3 = "(A + B) * (C + D)";
    cout << "Postfix Expression 1: " << infixToPostfix(infix1) << endl;
    cout << "Postfix Expression 2: " << infixToPostfix(infix2) << endl;
    cout << "Postfix Expression 3: " << infixToPostfix(infix3) << endl;
    return 0;
}
