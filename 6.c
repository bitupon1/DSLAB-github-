#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define MAX 100
// Stack structure for evaluating postfix expressions
typedef struct {
    int items[MAX];
    int top;
} Stack;
// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}
// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}
// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        s->items[++s->top] = value;
    }
}
// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return s->items[s->top--];
    }
}
// Function to evaluate a postfix expression
int evaluatePostfix(char *expression) {
    Stack s;
    initStack(&s);
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (isdigit(ch)) {
            // If the character is a digit, push it to the stack
            push(&s, ch - '0');
        } else {
            // Operator encountered, pop two elements
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            switch (ch) {
                case '+': push(&s, operand1 + operand2); break;
                case '-': push(&s, operand1 - operand2); break;
                case '*': push(&s, operand1 * operand2); break;
                case '/': push(&s, operand1 / operand2); break;
                case '%': push(&s, operand1 % operand2); break;
                case '^': push(&s, pow(operand1, operand2)); break;
                default: printf("Invalid operator encountered: %c\n", ch); return -1;
            }
        }
    }
    return pop(&s);  // The result of the expression
}
// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, target);
    printf("Move disk %d from %c to %c\n", n, source, target);
    towerOfHanoi(n - 1, auxiliary, target, source);
}
// Main function with menu-driven interface
int main() {
    int choice, n;
    char expression[MAX];
    while (1) {
        printf("\nMenu:\n");
        printf("1. Evaluate Postfix Expression\n");
        printf("2. Solve Tower of Hanoi Problem\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:  // Evaluate Postfix Expression
                printf("Enter a postfix expression: ");
                scanf("%s", expression);
                printf("Result of postfix evaluation: %d\n", evaluatePostfix(expression));
                break;
            case 2:  // Solve Tower of Hanoi Problem
                printf("Enter the number of disks: ");
                scanf("%d", &n);
                printf("Solution for Tower of Hanoi with %d disks:\n", n);
                towerOfHanoi(n, 'A', 'C', 'B');
                break;
            case 3:  // Exit
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}