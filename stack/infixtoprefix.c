#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100  // Increased buffer size

char stack[MAX];
int top = -1;

// Stack operations
void push(char x) {
    stack[++top] = x;
}

char pop() {
    return (top == -1) ? -1 : stack[top--];
}

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return -1;
}

// Function to reverse a string
void reverse(char *exp) {
    int i, j;
    char temp;
    int len = strlen(exp);
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

// Convert infix to prefix
void infixToPrefix(char *exp) {
    int len = strlen(exp);
    
    // Reset stack
    top = -1;

    // Step 1: Reverse the expression and swap brackets
    reverse(exp);
    for (int i = 0; i < len; i++) {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }

    // Step 2: Convert to postfix
    char result[MAX + 1]; // Extra space for null-terminator
    int resIndex = 0;
    
    for (int i = 0; i < len; i++) {
        if (isalnum(exp[i])) {
            result[resIndex++] = exp[i]; // Operand directly to result
        } else if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(')
                result[resIndex++] = pop();
            pop(); // Remove '(' from stack
        } else { // Operator
            while (top != -1 && priority(stack[top]) >= priority(exp[i]))
                result[resIndex++] = pop();
            push(exp[i]);
        }
    }

    while (top != -1) {
        result[resIndex++] = pop();
    }
    result[resIndex] = '\0';

    // Step 3: Reverse the postfix result to get prefix
    reverse(result);
    printf("Prefix Expression: %s\n", result);
}

// Driver function
int main() {
    char exp[MAX];

    printf("Enter the infix expression: ");
    fgets(exp, MAX, stdin);
    exp[strcspn(exp, "\n")] = '\0'; // Remove newline character

    infixToPrefix(exp);

    return 0;
}
