#include <stdio.h>
#include <stdlib.h>
// Define the structure of a node in the Doubly Linked List
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
// Function to create the Doubly Linked List
struct Node* createDoublyLinkedList() {
    int n, data;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    printf("Enter the number of nodes to create in the DLL: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode; // First node becomes head
            tail = newNode; // First node also becomes tail
        } else {
            tail->next = newNode; // Link new node after tail
            newNode->prev = tail;  // Link tail to new node
            tail = newNode;        // Update tail to new node
        }
    }
    return head;
}
// Function to print the DLL in forward traversal
void printForward(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Forward traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// Function to print the DLL in reverse traversal
void printReverse(struct Node* tail) {
    if (tail == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = tail;
    printf("Reverse traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
// Main function with menu-driven interface
int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Print DLL in Forward Traversal\n");
        printf("3. Print DLL in Reverse Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:  // Create Doubly Linked List
                head = createDoublyLinkedList();
                // Update tail pointer to the last node
                tail = head;
                while (tail != NULL && tail->next != NULL) {
                    tail = tail->next;
                }
                break;
            case 2:  // Print in Forward Traversal
                printForward(head);
                break;
            case 3:  // Print in Reverse Traversal
                printReverse(tail);
                break;
            case 4:  // Exit
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}