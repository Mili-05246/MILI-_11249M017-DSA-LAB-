#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Function declarations
void enqueue(int value);
void dequeue();
void peek();
void display();

int main() {
    int choice, value;

    printf("------ Queue Implementation using Linked List ------\n");

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Peek (Front Element)\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
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

// Function to insert element at rear
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted into the queue.\n", value);
}

// Function to delete element from front
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! No element to delete.\n");
        return;
    }

    struct Node* temp = front;
    printf("%d deleted from the queue.\n", front->data);
    front = front->next;

    if (front == NULL)  // If queue becomes empty
        rear = NULL;

    free(temp);
}

// Function to get the front element
void peek() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element is: %d\n", front->data);
    }
}

// Function to display the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
