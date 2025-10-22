#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    string arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(string str) { arr[++top] = str; }
    string pop() { return arr[top--]; }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string prefixToInfix(string prefix) {
    Stack s;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isalpha(c)) {
            s.push(string(1, c));  
        } else if (isOperator(c)) {
            string op1 = s.pop();
            string op2 = s.pop();
            string temp = "(" + op1 + c + op2 + ")";
            s.push(temp);
        }
    }
    return s.pop();
}

int main() {
    string prefix;
    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    string infix = prefixToInfix(prefix);
    cout << "Infix Expression: " << infix << endl;
    return 0;
}
