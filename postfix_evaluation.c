#include <stdio.h>
#include <ctype.h>   // for isdigit()

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = value;
}

// Pop function
int pop() {
    if (top == -1)
        return -1; // Stack underflow
    else
        return stack[top--];
}

// Postfix evaluation
int evaluatePostfix(char exp[]) {
    int i;
    int op1, op2;
    char symbol;

    for (i = 0; exp[i] != '\0'; i++) {
        symbol = exp[i];

        if (isdigit(symbol)) {
            // Convert char digit to integer and push
            push(symbol - '0');
        }
        else {
            // Operator: pop two operands
            op2 = pop();
            op1 = pop();

            switch (symbol) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '^': {
                    int result = 1;
                    for (int j = 0; j < op2; j++)
                        result *= op1;
                    push(result);
                    break;
                }
                default:
                    printf("Invalid operator %c\n", symbol);
                    return 0;
            }
        }
    }
    return pop(); // Final result
}

int main() {
    char exp[MAX];

    printf("Enter a postfix expression (single-digit operands): ");
    gets(exp); // Note: unsafe, used for simplicity

    int result = evaluatePostfix(exp);
    printf("Result of postfix expression: %d\n", result);

    return 0;
}
