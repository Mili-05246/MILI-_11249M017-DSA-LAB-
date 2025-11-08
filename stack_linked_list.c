#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Function declarations
void push(int value);
void pop();
void peek();
void display();

int main() {
    int choice, value;

    printf("------ Stack Implementation using Linked List ------\n");

    do {
        printf("\nMenu:\n");
        printf("1. Push (Insert)\n");
        printf("2. Pop (Delete)\n");
        printf("3. Peek (Top Element)\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to push an element
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto the stack.\n", value);
}

// Function to pop an element
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! No element to pop.\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped from the stack.\n", top->data);
    top = top->next;
    free(temp);
}

// Function to view the top element
void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", top->data);
    }
}

// Function to display all elements
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
