#include <stdio.h>
#define MAX_SIZE 100
void createArray(int arr[], int *size) {
    printf("Enter the number of elements in the array: ");
    scanf("%d", size);
    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }
}
void displayArray(int arr[], int size) {
    printf("Array elements are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insertElement(int arr[], int *size, int element, int pos) {
    if (pos < 0 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    (*size)++;
    printf("Element inserted successfully.\n");
}
void deleteElement(int arr[], int *size, int pos) {
    if (pos < 0 || pos >= *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element deleted successfully.\n");
}
int main() {
    int arr[MAX_SIZE], size = 0, choice, element, pos;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createArray(arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert (0 to %d): ", size);
                scanf("%d", &pos);
                insertElement(arr, &size, element, pos);
                break;
            case 4:
                printf("Enter the position to delete (0 to %d): ", size - 1);
                scanf("%d", &pos);
                deleteElement(arr, &size, pos);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}  