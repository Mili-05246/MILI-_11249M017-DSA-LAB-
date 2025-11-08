#include <stdio.h>
#define SIZE 10  // Size of hash table

int hashTable[SIZE];

// Function to initialize hash table
void initialize() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1; // -1 indicates empty cell
}

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Function to insert a key into the hash table
void insert(int key) {
    int index = hashFunction(key);
    int i = 0;

    // Linear probing in case of collision
    while (hashTable[(index + i) % SIZE] != -1 && i < SIZE) {
        i++;
    }

    if (i < SIZE) {
        hashTable[(index + i) % SIZE] = key;
        printf("Inserted %d at index %d\n", key, (index + i) % SIZE);
    } else {
        printf("Hash table is full! Cannot insert %d\n", key);
    }
}

// Function to search a key in the hash table
void search(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (hashTable[(index + i) % SIZE] != key && hashTable[(index + i) % SIZE] != -1 && i < SIZE)
        i++;

    if (hashTable[(index + i) % SIZE] == key)
        printf("Element %d found at index %d\n", key, (index + i) % SIZE);
    else
        printf("Element %d not found\n", key);
}

// Function to delete a key from hash table
void delete(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (hashTable[(index + i) % SIZE] != key && hashTable[(index + i) % SIZE] != -1 && i < SIZE)
        i++;

    if (hashTable[(index + i) % SIZE] == key) {
        hashTable[(index + i) % SIZE] = -1;
        printf("Element %d deleted from index %d\n", key, (index + i) % SIZE);
    } else {
        printf("Element %d not found for deletion\n", key);
    }
}

// Function to display the hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d → %d\n", i, hashTable[i]);
        else
            printf("Index %d → EMPTY\n", i);
    }
}

int main() {
    int choice, key;

    initialize();

    printf("------ Hash Table Implementation (Linear Probing) ------\n");

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
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
