#include <stdio.h>

#define MAX 100

// Function Declarations
void display(int arr[], int n);
int insert(int arr[], int n, int pos, int value);
int delete(int arr[], int n, int pos);
void search(int arr[], int n, int key);
void update(int arr[], int n, int pos, int value);

int main() {
    int arr[MAX];
    int n, choice, pos, value, key;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Search Element\n");
        printf("5. Update Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display(arr, n);
                break;
            case 2:
                printf("Enter position to insert (1 to %d): ", n+1);
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                n = insert(arr, n, pos, value);
                break;
            case 3:
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                n = delete(arr, n, pos);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &key);
                search(arr, n, key);
                break;
            case 5:
                printf("Enter position to update (1 to %d): ", n);
                scanf("%d", &pos);
                printf("Enter new value: ");
                scanf("%d", &value);
                update(arr, n, pos, value);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 6);

    return 0;
}

// Function Definitions

void display(int arr[], int n) {
    printf("Array elements are: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int insert(int arr[], int n, int pos, int value) {
    if(n >= MAX) {
        printf("Array overflow! Cannot insert.\n");
        return n;
    }
    if(pos < 1 || pos > n+1) {
        printf("Invalid position!\n");
        return n;
    }

    for(int i = n; i >= pos; i--)
        arr[i] = arr[i-1];

    arr[pos-1] = value;
    printf("Element inserted successfully.\n");
    return n + 1;
}

int delete(int arr[], int n, int pos) {
    if(n <= 0) {
        printf("Array underflow! No element to delete.\n");
        return n;
    }
    if(pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return n;
    }

    for(int i = pos-1; i < n-1; i++)
        arr[i] = arr[i+1];

    printf("Element deleted successfully.\n");
    return n - 1;
}

void search(int arr[], int n, int key) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Element %d found at position %d.\n", key, i+1);
            found = 1;
            break;
        }
    }
    if(!found)
        printf("Element not found.\n");
}

void update(int arr[], int n, int pos, int value) {
    if(pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return;
    }
    arr[pos-1] = value;
    printf("Element updated successfully.\n");
}
