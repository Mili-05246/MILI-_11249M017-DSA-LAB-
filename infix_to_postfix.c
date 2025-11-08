#include <stdio.h>
#include <ctype.h>   // for isalpha(), isdigit()
#include <string.h>  // for strlen()

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i, k = 0;
    char symbol;

    printf("Infix Expression: %s\n", infix);

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        if (isalnum(symbol)) { // Operand
            postfix[k++] = symbol;
        } 
        else if (symbol == '(') {
            push(symbol);
        } 
        else if (symbol == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop(); // Remove '(' from stack
        } 
        else { // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(symbol))
                postfix[k++] = pop();
            push(symbol);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0'; // Null terminate string

    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];

    printf("Enter an infix expression: ");
    gets(infix); // Note: gets() is unsafe but used for simplicity

    infixToPostfix(infix);

    return 0;
}
