#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Function declarations
void enqueue(int value);
void dequeue();
void peek();
void display();

int main() {
    int choice, value;

    printf("------ Queue Implementation using Array ------\n");

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

// Function to insert element in queue
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d.\n", value);
    } else {
        if (front == -1)
            front = 0;
        queue[++rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

// Function to delete element from queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No element to delete.\n");
    } else {
        printf("%d deleted from the queue.\n", queue[front]);
        front++;
    }
}

// Function to view front element
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

// Function to display all elements
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
