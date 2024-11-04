#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int top = -1;
// Function to check if stack is full
int isFull() {
    return top == MAX - 1;
}
// Function to check if stack is empty
int isEmpty() {
    return top == -1;
}
// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d onto stack.\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed onto stack.\n", value);
    }
}
// Function to pop an element from the stack
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop from stack.\n");
    } else {
        printf("%d popped from stack.\n", stack[top--]);
    }
}
// Function to check if a string is a palindrome using the stack
void checkPalindrome(char str[]) {
    int len = strlen(str);
    int mid = len / 2;
    for (int i = 0; i < mid; i++) {
        push(str[i]);
    }
    int start = (len % 2 == 0) ? mid : mid + 1;
    for (int i = start; i < len; i++) {
        if (isEmpty() || str[i] != stack[top]) {
            printf("The string \"%s\" is NOT a palindrome.\n", str);
            return;
        }
        top--; // pop the stack
    }
    printf("The string \"%s\" is a palindrome.\n", str);
}
// Function to display the stack
void displayStack() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main() {
    int choice, value;
    char str[MAX];
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push an Element onto Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Check Palindrome\n");
        printf("4. Demonstrate Overflow and Underflow\n");
        printf("5. Display Stack Status\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: // Push
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2: // Pop
                pop();
                break;
            case 3: // Palindrome Check
                printf("Enter a string to check palindrome: ");
                scanf("%s", str);
                checkPalindrome(str);
                top = -1; // reset stack after palindrome check
                break;
            case 4: // Overflow and Underflow Demonstration
                printf("Demonstrating Stack Overflow:\n");
                for (int i = 0; i <= MAX; i++) {
                    push(i + 1);
                }
                printf("Demonstrating Stack Underflow:\n");
                for (int i = 0; i <= MAX; i++) {
                    pop();
                }
                break;
            case 5: // Display Stack
                displayStack();
                break;
            case 6: // Exit
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}