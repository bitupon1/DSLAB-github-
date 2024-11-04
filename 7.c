
#include <stdio.h>
#include <stdlib.h>
#define MAX 5  // Maximum size of the circular queue
// Circular Queue structure
typedef struct {
    char items[MAX];
    int front, rear;
} CircularQueue;
// Function to initialize the queue
void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}
// Function to check if the queue is empty
int isEmpty(CircularQueue *q) {
    return q->front == -1;
}
// Function to check if the queue is full
int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}
// Function to insert an element into the circular queue
void enqueue(CircularQueue *q, char value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert '%c'.\n", value);
    } else {
        if (isEmpty(q)) {
            q->front = 0;  // Set front to 0 if queue was empty
        }
        q->rear = (q->rear + 1) % MAX;  // Circular increment
        q->items[q->rear] = value;
        printf("Inserted '%c' into the queue.\n", value);
    }
}
// Function to delete an element from the circular queue
void dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot delete from the queue.\n");
    } else {
        char value = q->items[q->front];
        if (q->front == q->rear) {
            // If the queue has only one element
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;  // Circular increment
        }
        printf("Deleted '%c' from the queue.\n", value);
    }
}
// Function to display the status of the circular queue
void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("The circular queue is empty.\n");
        return;
    }
    printf("Circular Queue: ");
    int i = q->front;
    while (1) {
        printf("%c ", q->items[i]);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % MAX;  // Circular increment
    }
    printf("\n");
}
// Main function to demonstrate the circular queue operations
int main() {
    CircularQueue q;
    initQueue(&q);
    int choice;
    char value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an Element onto Circular Queue\n");
        printf("2. Delete an Element from Circular Queue\n");
        printf("3. Demonstrate Overflow and Underflow\n");
        printf("4. Display Circular Queue Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: // Insert
                printf("Enter a character to insert: ");
                scanf(" %c", &value);  // Note the space before %c to consume any newline
                enqueue(&q, value);
                break;
            case 2: // Delete
                dequeue(&q);
                break;
            case 3: // Demonstrate Overflow and Underflow
                printf("Demonstrating Queue Overflow:\n");
                for (int i = 0; i < MAX + 1; i++) {
                    enqueue(&q, 'A' + i % 26);  // Insert characters A, B, C, ...
                }
                printf("Demonstrating Queue Underflow:\n");
                for (int i = 0; i < MAX + 1; i++) {
                    dequeue(&q);
                }
                break;
            case 4: // Display Queue
                displayQueue(&q);
                break;
            case 5: // Exit
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}