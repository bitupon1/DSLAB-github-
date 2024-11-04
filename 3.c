#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
// Function for Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
// Function for Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
// Function for Linear Search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}
// Function to display a sparse matrix
void displaySparseMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    printf("Sparse Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0)
                printf("Row: %d, Column: %d, Value: %d\n", i, j, matrix[i][j]);
        }
    }
}
// Function to calculate Fibonacci sequence up to n terms
void fibonacci(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci sequence:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}
// Function to calculate factorial of a number
unsigned long long factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}
// Utility function to display array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int choice, n, arr[MAX_SIZE], target, matrix[MAX_SIZE][MAX_SIZE], rows, cols;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Heap Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Linear Search\n");
        printf("4. Display Sparse Matrix\n");
        printf("5. Fibonacci Numbers\n");
        printf("6. Factorial of a Number\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: // Heap Sort
                printf("Enter the number of elements in the array: ");
                scanf("%d", &n);
                printf("Enter the elements:\n");
                for (int i = 0; i < n; i++)
                    scanf("%d", &arr[i]);
                heapSort(arr, n);
                printf("Array after Heap Sort:\n");
                displayArray(arr, n);
                break;
            case 2: // Quick Sort
                printf("Enter the number of elements in the array: ");
                scanf("%d", &n);
                printf("Enter the elements:\n");
                for (int i = 0; i < n; i++)
                    scanf("%d", &arr[i]);
                quickSort(arr, 0, n - 1);
                printf("Array after Quick Sort:\n");
                displayArray(arr, n);
                break;
            case 3: // Linear Search
                printf("Enter the number of elements in the array: ");
                scanf("%d", &n);
                printf("Enter the elements:\n");
                for (int i = 0; i < n; i++)
                    scanf("%d", &arr[i]);
                printf("Enter the element to search: ");
                scanf("%d", &target);
                int result = linearSearch(arr, n, target);
                if (result != -1)
                    printf("Element found at index %d\n", result);
                else
                    printf("Element not found\n");
                break;
            case 4: // Display Sparse Matrix
                printf("Enter the number of rows and columns: ");
                scanf("%d %d", &rows, &cols);
                printf("Enter the elements of the matrix:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        scanf("%d", &matrix[i][j]);
                    }
                }
                displaySparseMatrix(matrix, rows, cols);
                break;
            case 5: // Fibonacci Numbers
                printf("Enter the number of terms: ");
                scanf("%d", &n);
                fibonacci(n);
                break;
            case 6: // Factorial
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Factorial of %d is %llu\n", n, factorial(n));
                break;
            case 7: // Exit
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}