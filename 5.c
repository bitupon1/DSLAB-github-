#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
// Stack structure for storing operators
char stack[MAX];
int top = -1;
// Function to push an element to the stack
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = ch;
    }
}
// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}
// Function to get the precedence of operators
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': case '%': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}
// Function to determine if an operator is right associative
int isRightAssociative(char op) {
    return op == '^';
}
// Function to check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}
// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            // If the character is an operand, add it to postfix expression
            postfix[j++] = ch;
        } else if (ch == '(') {
            // If the character is '(', push it to stack
            push(ch);
        } else if (ch == ')') {
            // If the character is ')', pop and output until '(' is encountered
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop '(' from stack
        } else if (isOperator(ch)) {
            // Operator encountered
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                if (precedence(stack[top]) == precedence(ch) && isRightAssociative(ch))
                    break;
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}
// Main function
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}